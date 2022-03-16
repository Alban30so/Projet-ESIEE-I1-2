#include <stdio.h>
#include <windows.h>
#include "2j.c"
#include "4j.c"
#include "6j.c"
#pragma
void menu(){
    int nbj;
    printf("Bienvenue aux dames chinoises ! \n entrez le nombre de joueurs : \n");
    printf("1 joueur contre l'ordinateur : tapez 1\n");
    printf("2 joueurs sur le m%cme ordinateur : tapez 2\n",136);
    printf("4 joueurs sur le m%cme ordinateur : tapez 4\n",136);
    printf("6 joueurs sur le m%cme ordinateur : tapez 6\n",136);
    scanf("%i",&nbj);
    switch (nbj)
    {
    case 1:
        printf("Pas encore fonctionnel");
        break;
    case 2: 
        Jeu2();
        break;
    case 4:
        Jeu4();
        break;
    case 6 : 
        Jeu6();
        break;
    default:printf("Erreur de saisie, veuillez relancer.");
        break;
    }
}
int main(){
    menu();
}