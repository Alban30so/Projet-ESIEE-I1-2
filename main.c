#include <stdio.h>
#include<windows.h>
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
    int nbpion;//numéro du pion
    int pcase;//case occupée par le pion
    int equipe;//equipe de ce pion
    char nom;//
}pions;
void attpion(cases p[122], pions j[61]);
//Fonction permettant la réinitialisation du jeu et appelée au début pour remettre à 0 chaques variables
void reset(cases p[122], pions j[61]){
    int i;
    for(i=0;i<122;i++){
        p[i].nbcase=0;
        p[i].equipe=0;
        p[i].occupation=0;
        p[i].aff='.';
        j[i].nbpion=i;
        j[i].equipe=0;
        j[i].nom='0';
        j[i].pcase=0;
    }
    printf("Toutes les cases ont ete reinitialisee corectement !\n");
}
void saisiecases(cases p[122], pions j[61], int nbj){
    //cette fonciton saisie par défaut les cases pour un début de partie.
    int i;
    for(i=1;i<122;i++){
        p[i].nbcase=i;
        //printf("%i, ",p[i].nbcase);
    }
    attpion(p,j);
}
void base(cases p[122]){
    int i;
    for(i=0;i<122;i++){
        //Deux joueurs ou plus : Equipe Bleu et Jaune
        if(p[i].nbcase<=10&&p[i].nbcase>=0){
            p[i].equipe=1;//Equipe Bleu
        }
        //Equipe jaune
        if(p[i].nbcase>=112&&p[i].nbcase<=121){
            p[i].equipe=6;
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
        //Equipe noire ou grise
        if(p[i].nbcase==66||p[i].nbcase==76||p[i].nbcase==77){
            p[i].equipe=4;
        }
        else if(p[i].nbcase>=99&&p[i].nbcase<=102){
            p[i].equipe=4;
        }
        else if(p[i].nbcase>=87&&p[i].nbcase<=89){
            p[i].equipe=4;
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
            p[i].equipe=5;
        }
        else if(p[i].nbcase>=96&&p[i].nbcase<=98){
            p[i].equipe=5;
        }
        else if(p[i].nbcase>=108&&p[i].nbcase<=111){
            p[i].equipe=5;
        }
    }
}
void saisiedefaut(cases p[122],pions j[61],int nbj){
    base(p);
    j[1].pcase=1;
    j[2].pcase=2;
    j[3].pcase=3;
    j[4].pcase=4;
    j[5].pcase=5;
    j[6].pcase=6;
    j[7].pcase=7;
    j[8].pcase=8;
    j[9].pcase=9;
    j[10].pcase=10;
    j[11].pcase=11;
    j[12].pcase=12;
    j[13].pcase=13;
    j[14].pcase=14;
    j[15].pcase=24;
    j[16].pcase=25;
    j[17].pcase=26;
    j[18].pcase=36;
    j[19].pcase=37;
    j[20].pcase=47;
    j[21].pcase=20;
    j[22].pcase=21;
    j[23].pcase=22;
    j[24].pcase=23;
    j[25].pcase=33;
    j[26].pcase=34;
    j[27].pcase=35;
    j[28].pcase=45;
    j[29].pcase=46;
    j[30].pcase=56;
    j[31].pcase=66;
    j[32].pcase=76;
    j[33].pcase=77;
    j[34].pcase=87;
    j[35].pcase=88;
    j[36].pcase=88;
    j[37].pcase=89;
    j[38].pcase=99;
    j[39].pcase=100;
    j[40].pcase=101;
    j[41].pcase=102;
    j[42].pcase=75;
    j[43].pcase=85;
    j[44].pcase=86;
    j[45].pcase=96;
    j[46].pcase=97;
    j[47].pcase=98;
    j[48].pcase=108;
    j[49].pcase=109;
    j[50].pcase=110;
    j[51].pcase=111;
    j[52].pcase=112;
    j[53].pcase=114;
    j[54].pcase=115;
    j[55].pcase=116;
    j[56].pcase=117;
    j[57].pcase=118;
    j[58].pcase=119;
    j[59].pcase=120;
    j[60].pcase=121;
}
void attpion(cases p[122], pions j[61]){
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
    for(equ=1;equ<7;equ++){
        for(i=1;i<61;i++){
            temp=0;
            if(c1<=9&&temp==0){
                j[i].equipe=1;
                j[i].nom=nom[c1];
                c1+=1;
                temp=2;
            }
            if(c2<=9&&temp==0){
                j[i].equipe=2;
                j[i].nom=nom[c2];
                c2+=1;
                temp=2;
            }
            if(c3<=9&&temp==0){
                j[i].equipe=3;
                j[i].nom=nom[c3];
                c3+=1;
                temp=2;
            }
            if(c4<=9&&temp==0){
                j[i].equipe=4;
                j[i].nom=nom[c4];
                c4+=1;
                temp=2;
            }
            if(c5<=9&&temp==0){
                j[i].equipe=5;
                j[i].nom=nom[c5];
                c5+=1;
                temp=2;
            }
            if(c6<=9&&temp==0){
                j[i].equipe=6;
                j[i].nom=nom[c6];
                c6+=1;
                temp=2;
            }
        }
    }
}
void test(cases p[122], pions j[61]){
    int i;
    printf("Affichage liste joueurs\n");
    for(i=0;i<61;i++){
        printf("Numero de pion : %i  || Numero de case : %i  || equipe : %i  || nom : %c\n",j[i].nbpion,j[i].pcase,j[i].equipe,j[i].nom);
    }
}
void pionsgrille(cases p[122],pions j[61]){
    //Fonction permettant le remplacement de l'affichage des cases
    int i,z,temp=0,c=0;
    for(i=1;i<121;i++){
        temp=0;
        for(z=1;z<61;z++){
            if(j[z].pcase==p[i].nbcase){
                printf("Affichage case %i : %c",i,p[i].aff);
                p[i].aff=j[z].nom;
                printf("  Qui se transforme en %c\n",p[i].aff);
                temp=1;
            }
        }
    }
}
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
void testcolor(pions j[60],int i,int retour,cases p[122]){
    //char retour;
    int couleur;
    if( j[i].equipe==1 && j[i].pcase==p[i].nbcase){ //equipe bleue
        couleur=1;
    }
    if( j[i].equipe==2 && j[i].pcase==p[i].nbcase){//equipe rouge
        couleur=4;
    }
    if (j[i].equipe==3 && j[i].pcase==p[i].nbcase)// equipe blanche
    {
        couleur=15;
    }
    if (j[i].equipe==4 && j[i].pcase==p[i].nbcase) //equipe grise
    {
        couleur=7;
    }
    if (j[i].equipe==5 && j[i].pcase==p[i].nbcase) //equipe verte
    {
        couleur=2;
    }
    if (j[i].equipe==6 && j[i].pcase==p[i].nbcase) //equipe jaune
    {
        couleur=14;
    }
    if(couleur==0){ //probleme a regler
      couleur=5;
    }
    Color(couleur,0);
    printf("%c ",retour); 
    Color(15,0);
}

void affichage(cases p[122], pions j[60]){
    int l,compt=1;//variable représentant la ligne d'affichage
    int espace;
    printf("                   ---\n");
    pionsgrille(p,j);
    for(l=0;l<18;l++){
        if(l==1||l==17){
            for(espace=0;espace<9;espace++){
                printf("  ");
            }
            if(l==1){
                printf("/ ");
                testcolor(j,compt,p[compt].aff,p);
                printf("\\");
                printf("\n");
            }
            else{
                printf("\\ ");
                testcolor(j,compt,p[compt].aff,p);
                printf("/   ");
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
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                printf("\\ ");
                printf("\n");
            }
            else{
                printf(" \\ " );
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
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
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+3].aff,p);
                printf("\\ ");
                printf("\n");
            }
            else{
                printf("  \\ ");
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
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
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                printf("\\");
            }
            else{ 
                printf("\\ ");
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                printf("/");
            }
            printf("---------\n");
            compt+=4;
        }
        if(l==5||l==13){
            for(espace=0;espace<2;espace++){
                printf("  ");
            }
            if(l==5){
                printf("  \\ ");
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                testcolor(j,compt+4,p[compt+4].aff,p);
                testcolor(j,compt+5,p[compt+5].aff,p);
                testcolor(j,compt+6,p[compt+6].aff,p);
                testcolor(j,compt+7,p[compt+7].aff,p);
                testcolor(j,compt+8,p[compt+8].aff,p);
                testcolor(j,compt+9,p[compt+9].aff,p);
                testcolor(j,compt+10,p[compt+10].aff,p);
                testcolor(j,compt+11,p[compt+11].aff,p);
                testcolor(j,compt+12,p[compt+12].aff,p);
                printf("/");
                printf("\n");
            }
            else{
                printf("  / ");
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                testcolor(j,compt+4,p[compt+4].aff,p);
                testcolor(j,compt+5,p[compt+5].aff,p);
                testcolor(j,compt+6,p[compt+6].aff,p);
                testcolor(j,compt+7,p[compt+7].aff,p);
                testcolor(j,compt+8,p[compt+8].aff,p);
                testcolor(j,compt+9,p[compt+9].aff,p);
                testcolor(j,compt+10,p[compt+10].aff,p);
                testcolor(j,compt+11,p[compt+11].aff,p);
                testcolor(j,compt+12,p[compt+12].aff,p);
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
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                testcolor(j,compt+4,p[compt+4].aff,p);
                testcolor(j,compt+5,p[compt+5].aff,p);
                testcolor(j,compt+6,p[compt+6].aff,p);
                testcolor(j,compt+7,p[compt+7].aff,p);
                testcolor(j,compt+8,p[compt+8].aff,p);
                testcolor(j,compt+9,p[compt+9].aff,p);
                testcolor(j,compt+10,p[compt+10].aff,p);
                testcolor(j,compt+11,p[compt+11].aff,p);
                printf("/");
                printf("\n");
            }
            else{
                printf(" / ");
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                testcolor(j,compt+4,p[compt+4].aff,p);
                testcolor(j,compt+5,p[compt+5].aff,p);
                testcolor(j,compt+6,p[compt+6].aff,p);
                testcolor(j,compt+7,p[compt+7].aff,p);
                testcolor(j,compt+8,p[compt+8].aff,p);
                testcolor(j,compt+9,p[compt+9].aff,p);
                testcolor(j,compt+10,p[compt+10].aff,p);
                testcolor(j,compt+11,p[compt+11].aff,p);
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
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                testcolor(j,compt+4,p[compt+4].aff,p);
                testcolor(j,compt+5,p[compt+5].aff,p);
                testcolor(j,compt+6,p[compt+6].aff,p);
                testcolor(j,compt+7,p[compt+7].aff,p);
                testcolor(j,compt+8,p[compt+8].aff,p);
                testcolor(j,compt+9,p[compt+9].aff,p);
                testcolor(j,compt+10,p[compt+10].aff,p);
                printf("/");
                printf("\n");
            }
            else{
                printf("/ ");
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                testcolor(j,compt+4,p[compt+4].aff,p);
                testcolor(j,compt+5,p[compt+5].aff,p);
                testcolor(j,compt+6,p[compt+6].aff,p);
                testcolor(j,compt+7,p[compt+7].aff,p);
                testcolor(j,compt+8,p[compt+8].aff,p);
                testcolor(j,compt+9,p[compt+9].aff,p);
                testcolor(j,compt+10,p[compt+10].aff,p);
                printf("\\");
                printf("\n");
            }
            compt+=11;
        }
        if(l==8||l==10){
            for(espace=0;espace<4;espace++){
                printf("  ");
            }
            if(l==8){
                printf(" \\ ");
                testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                testcolor(j,compt+4,p[compt+4].aff,p);
                testcolor(j,compt+5,p[compt+5].aff,p);
                testcolor(j,compt+6,p[compt+6].aff,p);
                testcolor(j,compt+7,p[compt+7].aff,p);
                testcolor(j,compt+8,p[compt+8].aff,p);
                testcolor(j,compt+9,p[compt+9].aff,p);
                printf("/");
                printf("\n");
            }
            else{
                 printf(" / ");
                  testcolor(j,compt,p[compt].aff,p);
                testcolor(j,compt+1,p[compt+1].aff,p);
                testcolor(j,compt+2,p[compt+2].aff,p);
                testcolor(j,compt+3,p[compt+3].aff,p);
                testcolor(j,compt+4,p[compt+4].aff,p);
                testcolor(j,compt+5,p[compt+5].aff,p);
                testcolor(j,compt+6,p[compt+6].aff,p);
                testcolor(j,compt+7,p[compt+7].aff,p);
                testcolor(j,compt+8,p[compt+8].aff,p);
                testcolor(j,compt+9,p[compt+9].aff,p);
                printf("\\");
                printf("\n");
            }
            compt+=10;
        }
        if(l==9){
            for(espace=0;espace<4;espace++){
                printf("  ");
            }
            printf("  | ");
            testcolor(j,compt,p[compt].aff,p);
            testcolor(j,compt+1,p[compt+1].aff,p);
            testcolor(j,compt+2,p[compt+2].aff,p);
            testcolor(j,compt+3,p[compt+3].aff,p);
            testcolor(j,compt+4,p[compt+4].aff,p);
            testcolor(j,compt+5,p[compt+5].aff,p);
            testcolor(j,compt+6,p[compt+6].aff,p);
            testcolor(j,compt+7,p[compt+7].aff,p);
            testcolor(j,compt+8,p[compt+8].aff,p);
            printf("|");
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
void Jeu(cases p[122], pions j[60]){
    affichage(p,j);
    int run=1,tour=1,temp;
    char rep;
    while(run==1){
        printf("Au tour de l'equipe %i !\n",tour);
        do{
            printf("Veuillez Entrer la case :\n");
            scanf("%c",rep);
        }while(p[temp].equipe!=tour);

    }
}
int main(){
    cases plateau[122];
    pions joueurs[61];
    reset(plateau,joueurs);
    int i;
    for(i=0;i<122;i++){
        plateau[i].aff='.';
    }
    int nbj=menu();
    saisiecases(plateau,joueurs,nbj);
    saisiedefaut(plateau,joueurs,6);
    //test(plateau,joueurs);
    pionsgrille(plateau,joueurs);
    affichage(plateau,joueurs);
}