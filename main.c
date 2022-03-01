#include <stdio.h>
#include <windows.h>
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
void reset(cases p[122]){
    int i;
    for(i=0;i<122;i++){
        p[i].nbcase=0;
        p[i].equipe=0;
        p[i].occupation=0;
        p[i].aff=0;
    }
    printf("Toutes les cases ont ete reinitialisee corectement !\n");
}
void saisiecases(cases p[122],int nbj){
    //cette fonciton saisie par défaut les cases pour un début de parti.
    int i,t1,t2,t3,t4;
    if(nbj==2){
        t1=2;
    }
    else if(nbj==4){
        t1=4;
        t2=3;
    }
    else if(nbj==6){
        t1=6;
        t2=5;
    }
    //saisie des numéros de cases automatiquement.
    for(i=1;i<122;i++){
        p[i].nbcase=i;
        //printf("%i, ",p[i].nbcase);
    }
    for(i=0;i<122;i++){
        //Deux joueurs ou plus : Equipe Bleu et Jaune
        if(p[i].nbcase<=10&&p[i].nbcase>=0){
            p[i].equipe=1;//Equipe rougeu
        }
        //Equipe jaune
        if(p[i].nbcase>=112&&p[i].nbcase<=121){
            p[i].equipe=t1;
        }
        if(nbj>=4){
            if(nbj==6){
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
            //Equipe verte
            if(p[i].nbcase==75||p[i].nbcase==85||p[i].nbcase==86){
                p[i].equipe=t2;
            }
            else if(p[i].nbcase>=96&&p[i].nbcase<=98){
                p[i].equipe=t2;
            }
            else if(p[i].nbcase>=108&&p[i].nbcase<=111){
                p[i].equipe=t2;
            }
        }
    }
}
void test(cases p[122]){
    int i;
    for(i=0;i<121;i++){
        printf("Numero de case : %i   || equipe : %i\n",p[i].nbcase,p[i].equipe);
    }
}
//La variable aff des cases est changé en fonction de si elle est remplie ou pas
//Si oui alors il sera affiché "  " sinon il sera affiché le numéro de l'équipe.
int prescases(cases p[122],pions j[60],int i){
    int temp;
    if(p[i].occupation==0){
        temp=j[i].equipe;
    }
    else{
        temp=0;
    }
    return temp; 
}
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void testcolor(pions j[60],int i,int retour){
    //char retour;
    int couleur;
    if(j[i].equipe==1){
        couleur=12;
    }
    if(j[i].equipe==2){
        couleur=11;
    }
    if (j[i].equipe==3)
    {
        couleur=10;
    }
    if (j[i].equipe==4)
    {
        couleur=14;
    }
    if (j[i].equipe==5)
    {
        couleur=1;
    }
    if (j[i].equipe==6)
    {
        couleur=15;
    }
    else{
        couleur=5;
    }
    Color(couleur,0);
    printf("%i",retour); 
    Color(15,0);
}
void affichage(cases p[122], pions j[60]){
    int l,compt=1;//variable représentant la ligne d'affichage
    int espace;
    printf("                   ---\n");
    for(l=0;l<18;l++){
        if(l==1||l==17){
            for(espace=0;espace<9;espace++){
                printf("  ");
            }
            if(l==1){
                printf("/ ");
                testcolor(j,compt,p[compt].equipe);
                printf(" \\");
                printf("\n");
            }
            else{
                printf("\\ %i /",p[compt].equipe);
                printf("\n");
            }
            compt+=1;
        }
        if(l==2||l==16){
            for(espace=0;espace<8;espace++){
                printf("  ");
            }
            if(l==2){
                printf(" / %i %i \\",p[compt].equipe,p[compt+1].equipe);
                printf("\n");
            }
            else{
                printf(" \\ %i %i /",p[compt].equipe,p[compt+1].equipe);
                printf("\n");
            }
            compt+=2;
        }
        if(l==3||l==15){
            for(espace=0;espace<7;espace++){
                printf("  ");
            }
            if(l==3){
            
                printf("  / %i %i %i \\",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe);

                printf("\n");
            }
            else{
                printf("  \\ %i %i %i /",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe);
                printf("\n");
            }

            compt+=3;
        }    
        if(l==4||l==14){
            for(espace=0;espace<3;espace++){
                printf("  ");
            }
            printf("---------");
            if(l==4){
                printf("/ %i %i %i %i \\---------",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe);
                printf("\n");
            }
            else{ 
                printf("\\ %i %i %i %i /---------",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe);
                printf("\n");
            }
            compt+=4;
        }
        if(l==5||l==13){
            for(espace=0;espace<2;espace++){
                printf("  ");
            }
            if(l==5){
                printf("  \\ %i %i %i %i %i %i %i %i %i %i %i %i %i /",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe,p[compt+9].equipe,p[compt+10].equipe,p[compt+11].equipe,p[compt+12].equipe);
                printf("\n");
            }
            else{
                printf("  / %i %i %i %i %i %i %i %i %i %i %i %i %i \\",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe,p[compt+9].equipe,p[compt+10].equipe,p[compt+11].equipe,p[compt+12].equipe);
                printf("\n");
            }
            compt+=13;
        }
        if(l==6||l==12){
            for(espace=0;espace<3;espace++){
                printf("  ");
            }
            if(l==6){
                printf(" \\ %i %i %i %i %i %i %i %i %i %i %i %i /",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe,p[compt+9].equipe,p[compt+10].equipe,p[compt+11].equipe);
                printf("\n");
            }
            else{
                printf(" / %i %i %i %i %i %i %i %i %i %i %i %i \\",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe,p[compt+9].equipe,p[compt+10].equipe,p[compt+11].equipe);
                printf("\n");
            }
            compt+=12;
        }
        if(l==7||l==11){
            for(espace=0;espace<4;espace++){
                printf("  ");
            }
            if(l==7){
                printf("\\ %i %i %i %i %i %i %i %i %i %i %i /",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe,p[compt+9].equipe,p[compt+10].equipe);
                printf("\n");
            }
            else{
                printf("/ %i %i %i %i %i %i %i %i %i %i %i \\",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe,p[compt+9].equipe,p[compt+10].equipe);
                printf("\n");
            }
            compt+=11;
        }
        if(l==8||l==10){
            for(espace=0;espace<4;espace++){
                printf("  ");
            }
            if(l==8){
                printf(" \\ %i %i %i %i %i %i %i %i %i %i /",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe,p[compt+9].equipe);
                printf("\n");
            }
            else{
                 printf(" / %i %i %i %i %i %i %i %i %i %i \\",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe,p[compt+9].equipe);
                printf("\n");
            }
            compt+=10;
        }
        if(l==9){
            for(espace=0;espace<4;espace++){
                printf("  ");
            }
            printf("  | %i %i %i %i %i %i %i %i %i |",p[compt].equipe,p[compt+1].equipe,p[compt+2].equipe,p[compt+3].equipe,p[compt+4].equipe,p[compt+5].equipe,p[compt+6].equipe,p[compt+7].equipe,p[compt+8].equipe);
            printf("\n");
            compt+=9;
        }
    }
    printf("                   ---\n");
}

int menu(){
    int nbj;
    printf("Bienvenue aux dames chinoises ! \n entrez le nombre de joueurs : \n");
    printf("1 joueur contre l'ordinateur : tapez 1\n");
    printf("2 joueurs sur le meme ordinateur : tapez 2\n");
    printf("4 joueurs sur le meme ordinateur : tapez 4\n");
    printf("6 joueurs sur le même ordinateur : tapez 6\n");
    scanf("%i",&nbj);
    switch (nbj)
    {
    case 1:
        return 1;
        break;
    case 2: 
        return 2;
        break;
    case 4:
        return 4;
        break;
    case 6 : 
        return 6;
        break;
    default:printf("Erreur de saisie, veuillez relancer.");
        return 0;
        break;
    }
}

void couleur(){
   Color(12,3);
   printf("La ton texte va avoir la couleur 12 comme texte et 3 pour fond");
   Color(15, 0);
}

int main(){
    cases plateau[122];
    pions joueurs[60];
    reset(plateau);
    int nbj=menu();
    saisiecases(plateau,nbj);
    //test(plateau);
    affichage(plateau,joueurs);
    printf("A vous de jouer !\n");
    couleur();
    
}