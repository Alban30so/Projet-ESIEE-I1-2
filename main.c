#include <stdio.h>
//Ce code est celui du jeu en affichage console.
typedef struct cases
{
    int nbcase;//Numéro de la case
    int equipe;//Equipe de la case, 0 si neutre
    int occupation;// Ocupation de la case 0/1
    int aff;//Affichage du pion "  " si vide
}cases;
typedef struct pions
{
    int pcase;//case occupée par le pion
    int equipe;//equipe de ce pion
}pions;
//Fonction permettant la réinitialisation du jeu et appelée au début pour remettre à 0 chaques variables
void reset(cases p[121]){
    int i;
    for(i=0;i<122;i++){
        p[i].nbcase=0;
        p[i].equipe=0;
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
            p[i].equipe=1;//Equipe Bleu
        }
        //Equipe rouge
        if(p[i].nbcase==47||p[i].nbcase==36||p[i].nbcase==37){
            p[i].equipe=2;
        }
        else if(p[i].nbcase<=14&&p[i].nbcase>=11){
            p[i].equipe=2;
        }
        else if(p[i].nbcase<=26&&p[i].nbcase>=24){
            p[i].equipe=2;
        }
        //Equipe blanche
        if(p[i].nbcase==56||p[i].nbcase==45||p[i].nbcase==46){
            p[i].equipe=3;
        }
        else if(p[i].nbcase>=20&&p[i].nbcase<=23){
            p[i].equipe=3;
        }
        else if(p[i].nbcase>=33&&p[i].nbcase<=35){
            p[i].equipe=3;
        }
        //Equipe noire
        if(p[i].nbcase==66||p[i].nbcase==76||p[i].nbcase==77){
            p[i].equipe=4;
        }
        else if(p[i].nbcase>=99&&p[i].nbcase<=102){
            p[i].equipe=4;
        }
        else if(p[i].nbcase>=87&&p[i].nbcase<=89){
            p[i].equipe=4;
        }
        //Equipe verte
        if(p[i].nbcase==75||p[i].nbcase==85||p[i].nbcase==86){
            p[i].equipe=5;
        }
        else if(p[i].nbcase>=96&&p[i].nbcase<=98){
            p[i].equipe=5;
        }
        else if(p[i].nbcase>=108&&p[i].nbcase<=111){
            p[i].equipe=5;
        }
        //Equipe jaune
        if(p[i].nbcase>=112&&p[i].nbcase<=121){
            p[i].equipe=6;
        }
    }
}
void test(cases p[121]){
    int i;
    for(i=0;i<121;i++){
        printf("Numero de case : %i   || equipe : %i\n",p[i].nbcase,p[i].equipe);
    }
}
//La variable aff des cases est changé en fonction de si elle est remplie ou pas
//Si oui alors il sera affiché "  " sinon il sera affiché le numéro de l'équipe.
int prescases(cases p[121],pions j[60],int i){
    int temp;
    if(p[i].occupation==0){
        temp=j[i].equipe;
    }
    else{
        temp=0;
    }
    return temp;
}
void affichage(cases p[121], pions j[60]){

}
int main(){
    cases plateau[121];
    pions joueurs[60];
    reset(plateau);
    saisiecases(plateau);
    test(plateau);
    printf("Hello World");
}