#include <SDL/SDL.h>
#include <stdio.h>
#define OUI 1
#define NON 0
void pause(){
    int continuer=OUI;
    SDL_Event event;
    while(continuer==OUI){
        SDL_WaitEvent(&event);
        if(event.type==SDL_QUIT){
            continuer=NON;
        }
    }
}
int main (int argc, char**argv){
    SDL_Surface*ecran,*newrectangle,*fond;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Rect position;
    ecran=SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
    SDL_WM_SetCaption("Ecran de jeu",NULL);
    Uint32 blanc=SDL_MapRGB(ecran->format,255,255,255);
    SDL_FillRect(ecran,NULL,blanc);
    newrectangle=SDL_CreateRGBSurface(SDL_HWSURFACE,100,100,32,0,0,0,0);
    position.x=400-150;position.y=300-100;
    SDL_BlitSurface(newrectangle,NULL,ecran,&position);
    SDL_Flip(ecran);
    pause();
    return 0;
}
/*
int main ( int argc, char** argv ){
    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(1200,700, 16,SDL_HWSURFACE|SDL_DOUBLEBUF);
    // load an image
    SDL_Surface* bmp = SDL_LoadBMP("plateau.bmp");
    if (!bmp)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }
    // centre the image
    SDL_Rect dstrect={0,0,100,100};

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

#include <stdio.h>
#include <SDL2/SDL.H>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char** argv){
    if(SDL_Init(SDL_INIT_EVERYTHING)<0){
        printf("Error : SDL failed to initialize");
        return 1;
    }
    SDL_Window *window=SDL_CreateWindow("Jeu de dames chinois", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,0);
    if(!window){
        printf("Error: Failed to open window\n SDL Error:'%s'\n",SDL_GetError());
        return 1;
    }

    return 0;
}
*/
