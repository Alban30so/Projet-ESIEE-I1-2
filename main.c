#include <stdio.h>
#include <windows.h>
//Ce code est celui du jeu en affichage console.
typedef struct cases
{
    int nbcase;//Numéro de la case
    int equipe;//Equipe de la case, 0 si neutre
    int occupation;// Ocupation de la case 0/1
    char aff;//Affichage du pion "  " si vide
}cases;
typedef struct pions
{
    int pcase;//case occupée par le pion
    int equipe;//equipe de ce pion
}pions;
void attpion(cases p[122], pions j[60], int nbj);
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
void saisiecases(cases p[122], pions j[60], int nbj){
    //cette fonciton saisie par défaut les cases pour un début de partie.
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
            p[i].equipe=1;//Equipe Bleu
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
        attpion(p,j,nbj);
    }
}
void attpion(cases p[122], pions j[61], int nbj){
    int equ=1,i,temp=0;
    char nom[10];
    nom[0]='1';
    nom[1]='2';
    nom[2]='3';
    nom[3]='4';
    nom[4]='5';
    nom[5]='6';
    nom[6]='7';
    nom[7]='8';
    nom[8]='9';
    nom[9]='0';
    int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0;
    if(nbj==6){
        for(i=1;i<61;i++){
            j[i].equipe=equ;
            j[i].nom=nom[temp];
            temp+=1;
            if(temp==10){
                equ+=1;
                temp=0;
            }
        }
    }
    if(nbj==4){
        for(i=1;i<11;i++){
            j[i].equipe=1;
        }
        for(i=11;i<21;i++){
            j[i].equipe=2;
        }
        for(i=41;i<51;i++){
            j[i].equipe=3;
        }
        for(i=51;i<61;i++){
            j[i].equipe=4;
        }

    }
    if(nbj==2){
        for(i=1;i<11;i++){
            j[i].equipe=1;
        }
        for(i=51;i<61;i++){
            j[i].equipe=2;
        }
    }
void test(cases p[122]){
    int i;
    for(i=0;i<121;i++){
        printf("Numero de case : %i   || equipe : %i  || affichage : %c\n",p[i].nbcase,p[i].equipe,p[i].aff);
    }
}
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void testcolor(pions j[60],int i,int retour){
    //char retour;
    int couleur;
    if( j[i].equipe==1){
        couleur=12;
    }
    if( j[i].equipe==2){
        couleur=11;
    }
    if (j[i].equipe==3)
    {
        couleur=13;
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
        couleur=10;
    }
    Color(couleur,0);
    printf("%c ",retour); 
    Color(15,0);
}
<<<<<<< Updated upstream
=======

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void testcolor(pions j[60],int i,int retour){
    //char retour;
    int couleur;
    if( j[i].equipe==1){
        couleur=12;
    }
    if( j[i].equipe==2){
        couleur=11;
    }
    if (j[i].equipe==3)
    {
        couleur=13;
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
        couleur=10;
    }
    Color(couleur,0);
    printf("%c ",retour); 
    Color(15,0);
}
>>>>>>> Stashed changes
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
                testcolor(j,compt,p[compt].aff);
                printf("\\");
                printf("\n");
            }
            else{
                printf("\\ ");
                testcolor(j,compt,p[compt].aff);
                printf("/");
                printf("\n");
            }
            compt+=1;
        }
        if(l==2||l==16){
            for(espace=0;espace<8;espace++){
                printf("  ");
            }
            if(l==2){
                printf(" / ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                printf("\\ ");
                printf("\n");
            }
            else{
                printf(" \\ " );
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                printf("/");
                printf("\n");
            }
            compt+=2;
        }
        if(l==3||l==15){
            for(espace=0;espace<7;espace++){
                printf("  ");
            }
            if(l==3){
            
                printf("  / ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+3].aff);
                printf("\\ ");
                printf("\n");
            }
            else{
                printf("  \\ ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+2].aff);
                printf("/");
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
                printf("/ ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+2].aff);
                testcolor(j,compt+3,p[compt+3].aff);
                printf("\\");
                printf("\n");
            }
            else{ 
                printf("\\ ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+2].aff);
                testcolor(j,compt+3,p[compt+3].aff);
                printf("/");
                printf("\n");
            }
            compt+=4;
        }
        if(l==5||l==13){
            for(espace=0;espace<2;espace++){
                printf("  ");
            }
            if(l==5){
                printf("  \\ ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+2].aff);
                testcolor(j,compt+3,p[compt+3].aff);
                testcolor(j,compt+4,p[compt+4].aff);
                testcolor(j,compt+5,p[compt+5].aff);
                testcolor(j,compt+6,p[compt+6].aff);
                testcolor(j,compt+7,p[compt+7].aff);
                testcolor(j,compt+8,p[compt+8].aff);
                testcolor(j,compt+9,p[compt+9].aff);
                testcolor(j,compt+10,p[compt+10].aff);
                testcolor(j,compt+11,p[compt+11].aff);
                testcolor(j,compt+12,p[compt+12].aff);
                printf("\n");
            }
            else{
                printf("  / ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+2].aff);
                testcolor(j,compt+3,p[compt+3].aff);
                testcolor(j,compt+4,p[compt+4].aff);
                testcolor(j,compt+5,p[compt+5].aff);
                testcolor(j,compt+6,p[compt+6].aff);
                testcolor(j,compt+7,p[compt+7].aff);
                testcolor(j,compt+8,p[compt+8].aff);
                testcolor(j,compt+9,p[compt+9].aff);
                testcolor(j,compt+10,p[compt+10].aff);
                testcolor(j,compt+11,p[compt+11].aff);
                testcolor(j,compt+12,p[compt+12].aff);
                printf("\\");
                printf("\n");
            }
            compt+=13;
        }
        if(l==6||l==12){
            for(espace=0;espace<3;espace++){
                printf("  ");
            }
            if(l==6){
                printf(" \\ ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+2].aff);
                testcolor(j,compt+3,p[compt+3].aff);
                testcolor(j,compt+4,p[compt+4].aff);
                testcolor(j,compt+5,p[compt+5].aff);
                testcolor(j,compt+6,p[compt+6].aff);
                testcolor(j,compt+7,p[compt+7].aff);
                testcolor(j,compt+8,p[compt+8].aff);
                testcolor(j,compt+9,p[compt+9].aff);
                testcolor(j,compt+10,p[compt+10].aff);
                testcolor(j,compt+11,p[compt+11].aff);
                printf("/");
                printf("\n");
            }
            else{
                printf(" / ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+2].aff);
                testcolor(j,compt+3,p[compt+3].aff);
                testcolor(j,compt+4,p[compt+4].aff);
                testcolor(j,compt+5,p[compt+5].aff);
                testcolor(j,compt+6,p[compt+6].aff);
                testcolor(j,compt+7,p[compt+7].aff);
                testcolor(j,compt+8,p[compt+8].aff);
                testcolor(j,compt+9,p[compt+9].aff);
                testcolor(j,compt+10,p[compt+10].aff);
                testcolor(j,compt+11,p[compt+11].aff);
                printf("\\");
                printf("\n");
            }
            compt+=12;
        }
        if(l==7||l==11){
            for(espace=0;espace<4;espace++){
                printf("  ");
            }
            if(l==7){
                printf("\\ ");
                testcolor(j,compt,p[compt].aff);
                testcolor(j,compt+1,p[compt+1].aff);
                testcolor(j,compt+2,p[compt+2].aff);
                testcolor(j,compt+3,p[compt+3].aff);
                testcolor(j,compt+4,p[compt+4].aff);
                testcolor(j,compt+5,p[compt+5].aff);
                testcolor(j,compt+6,p[compt+6].aff);
                testcolor(j,compt+7,p[compt+7].aff);
                testcolor(j,compt+8,p[compt+8].aff);
                testcolor(j,compt+9,p[compt+9].aff);
                testcolor(j,compt+10,p[compt+10].aff);
                printf("/");
                printf("\n");
            }
            else{
                printf("/ %c %c %c %c %c %c %c %c %c %c %c \\",p[compt].aff,p[compt+1].aff,p[compt+2].aff,p[compt+3].aff,p[compt+4].aff,p[compt+5].aff,p[compt+6].aff,p[compt+7].aff,p[compt+8].aff,p[compt+9].aff,p[compt+10].aff);
                printf("\n");
            }
            compt+=11;
        }
        if(l==8||l==10){
            for(espace=0;espace<4;espace++){
                printf("  ");
            }
            if(l==8){
                printf(" \\ %c %c %c %c %c %c %c %c %c %c /",p[compt].aff,p[compt+1].aff,p[compt+2].aff,p[compt+3].aff,p[compt+4].aff,p[compt+5].aff,p[compt+6].aff,p[compt+7].aff,p[compt+8].aff,p[compt+9].aff);
                printf("\n");
            }
            else{
                 printf(" / %c %c %c %c %c %c %c %c %c %c \\",p[compt].aff,p[compt+1].aff,p[compt+2].aff,p[compt+3].aff,p[compt+4].aff,p[compt+5].aff,p[compt+6].aff,p[compt+7].aff,p[compt+8].aff,p[compt+9].aff);
                printf("\n");
            }
            compt+=10;
        }
        if(l==9){
            for(espace=0;espace<4;espace++){
                printf("  ");
            }
            printf("  | %c %c %c %c %c %c %c %c %c |",p[compt].aff,p[compt+1].aff,p[compt+2].aff,p[compt+3].aff,p[compt+4].aff,p[compt+5].aff,p[compt+6].aff,p[compt+7].aff,p[compt+8].aff);
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
    printf("6 joueurs sur le meme ordinateur : tapez 6\n");
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

int main(){
    cases plateau[122];
    pions joueurs[60];
    reset(plateau);
    int nbj=menu();
    saisiecases(plateau,joueurs,nbj);
    //test(plateau);
    affichage(plateau,joueurs);
    printf("A vous de jouer !\n");
}