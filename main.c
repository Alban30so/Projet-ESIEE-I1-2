#include <stdio.h>
//Ce code est celui du jeu en affichage console.
typedef struct cases
{
    int nbcase;
    int camp;
    int occupation;
}cases;
//Fonction permettant la réinitialisation du jeu et appelée au début pour remettre à 0 chaques variables
void reset(cases p[121]){
    int i;
    for(i=0;i<122;i++){
        p[i].nbcase=0;
        p[i].camp=0;
        p[i].occupation=0;
    }
    printf("Toutes les cases ont ete reinitialisee corectement !\n");
}
void saisiecases(cases p[121]){
    //cette fonciton saisie par défaut les cases pour un début de parti.
    int i;
    //saisie des numéros de cases automatiquement.
    for(i=1;i<122;i++){
        p[i].nbcase=i;
        //printf("%i, ",p[i].nbcase);
    }
    for(i=0;i<121;i++){
        if(p[i].nbcase<=10&&p[i].nbcase>=0){
            p[i].camp=1;//Equipe Bleu
        }
        /*
        if(p[i].nbcase){
            p[i].camp=2;
        }
        if(p[i].nbcase){
            p[i].camp=3;
        }
        if(p[i].nbcase){
            p[i].camp=4;
        }
        if(p[i].nbcase){
            p[i].camp=5;
        }*/
        if(p[i].nbcase>=112&&p[i].nbcase<=121){
            p[i].camp=6;//Equipe jaune
        }
    }
}
void test(cases p[121]){
    int i;
    for(i=0;i<121;i++){
        printf("Numero de case : %i   || equipe : %i\n",p[i].nbcase,p[i].camp);
    }
}
int main(){
    cases plateau[121];
    reset(plateau);
    saisiecases(plateau);
    test(plateau);
    printf("Hello World");
}