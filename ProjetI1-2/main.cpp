#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>


int main ( int argc, char** argv ){





    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(1200,700, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    // load an image
    SDL_Surface* bmp = SDL_LoadBMP("plateau.bmp");
    if (!bmp)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    // centre the image
    SDL_Rect dstrect={0,0,500,50};

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        // draw bitmap
        SDL_BlitSurface(bmp, 0, screen, &dstrect);

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    }
    // free loaded bitmap
    SDL_FreeSurface(bmp);
    return 0;
}
