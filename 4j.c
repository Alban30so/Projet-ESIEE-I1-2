#include <stdio.h>
#include<windows.h>
//Ce code est celui du jeu en affichage console.
typedef struct cases4
{
    int nbcase;//Numéro de la case
    int equipe;//Equipe de la case, 0 si neutre
    int occupation;// Ocupation de la case 0/1
    char aff;//Affichage du pion "." si vide
}cases4;
typedef struct pions4
{
    int nbpion;//numéro du pion
    int pcase;//case occupée par le pion
    int equipe;//equipe de ce pion
    char nom;//
}pions4;
void attpion4(cases4 p[122], pions4 j[41]);
//Fonction permettant la réinitialisation du jeu et appelée au début pour remettre à 0 chaques variables
void reset4(cases4 p[122], pions4 j[41]){
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
    //printf("Toutes les cases4 ont ete reinitialisee corectement !\n");
}
void saisiecases4(cases4 p[122], pions4 j[41]){
    //cette fonciton saisie par défaut les cases4 pour un début de partie.
    int i;
    for(i=1;i<122;i++){
        p[i].nbcase=i;
        //printf("%i, ",p[i].nbcase);
    }
    attpion4(p,j);
}
void base4(cases4 p[122]){
    int i;
    for(i=0;i<122;i++){
        //Deux joueurs ou plus : Equipe Bleu et Jaune
        if(p[i].nbcase<=10&&p[i].nbcase>=0){
            p[i].equipe=1;//Equipe Bleu
        }
        //Equipe jaune
        if(p[i].nbcase>=112&&p[i].nbcase<=121){
            p[i].equipe=2;
        }
        //Equipe rouge
        if(p[i].nbcase==47||p[i].nbcase==36||p[i].nbcase==37){
            p[i].equipe=3;
        }
        else if(p[i].nbcase<=14&&p[i].nbcase>=11){
            p[i].equipe=3;
        }
        else if(p[i].nbcase<=26&&p[i].nbcase>=24){
            p[i].equipe=3;
        }
        //Equipe verte
        if(p[i].nbcase==75||p[i].nbcase==85||p[i].nbcase==86){
            p[i].equipe=4;
        }
        else if(p[i].nbcase>=96&&p[i].nbcase<=98){
            p[i].equipe=4;
        }
        else if(p[i].nbcase>=108&&p[i].nbcase<=111){
            p[i].equipe=4;
        }
    }
}
void saisiedefaut4 (cases4 p[122],pions4 j[41],int nbj){
    base4(p);
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
    j[21].pcase=75;
    j[22].pcase=85;
    j[23].pcase=86;
    j[24].pcase=96;
    j[25].pcase=97;
    j[26].pcase=98;
    j[27].pcase=108;
    j[28].pcase=109;
    j[29].pcase=110;
    j[30].pcase=111;
    j[31].pcase=112;
    j[32].pcase=113;
    j[33].pcase=114;
    j[34].pcase=115;
    j[35].pcase=116;
    j[36].pcase=117;
    j[37].pcase=118;
    j[38].pcase=119;
    j[39].pcase=120;
    j[40].pcase=121;
}
void attpion4(cases4 p[122], pions4 j[41]){
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
        for(i=1;i<41;i++){
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
        }
    }
}
void test4(cases4 p[122], pions4 j[41]){
    int i;
    printf("Affichage liste joueurs\n");
    for(i=0;i<41;i++){
        printf("Numero de pion : %i  || Numero de case : %i  || equipe : %i  || nom : %c\n",j[i].nbpion,j[i].pcase,j[i].equipe,j[i].nom);
    }
}
cases4* pions4grille(cases4 p[122],pions4 j[41]){
    //Fonction permettant le remplacement de l'affichage des cases4
    int i,z,temp=0,c=0;
    for(i=1;i<121;i++){
        temp=0;
        for(z=1;z<41;z++){
            if(j[z].pcase==p[i].nbcase){
                //printf("Affichage case %i : %c",i,p[i].aff);
                p[i].aff=j[z].nom;
                //printf("  Qui se transforme en %c\n",p[i].aff);
                temp=1;
            }
        }
    }
    return p;
}
void Color4(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int identification4(pions4 j[41], cases4 p[122], int i){
    int z;
    for(z=1;z<41;z++){
        if(p[i].nbcase==j[z].pcase){
            return z;
            printf("Je suis rentre\n");
        }
    }
}
void testcolor4(pions4 j[41],int i, cases4 p[122]){
    int z, temp=0;
    int couleur;
    z=identification4(j,p,i);
    if(j[z].equipe==1){
        couleur=1;
        temp=1;
    }
    if(j[z].equipe==2){
        couleur=4;
        temp=1;
    }
    if(j[z].equipe==3){
        couleur=15;
        temp=1;
    }
    if(j[z].equipe==4){
        couleur=14;
        temp=1;
    }
    if(temp==1){
        Color4(couleur,0);
        printf("%c ",j[z].nom);
        Color4(15,0);
    }
    else{
        Color4(15,0);
        printf(". ");
        Color4(15,0);
    }
}
void affichage4(cases4 p[122], pions4 j[60]){
    int l,compt=1;//variable représentant la ligne d'affichage
    int espace;
    printf("                   ---\n");
    p=pions4grille(p,j);
    for(l=0;l<18;l++){
        if(l==1||l==17){
            for(espace=0;espace<9;espace++){
                printf("  ");
            }
            if(l==1){
                printf("/ ");
                testcolor4(j,compt,p);
                printf("\\");
                printf("\n");
            }
            else{
                printf("\\ ");
                testcolor4(j,compt,p);
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
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                printf("\\ ");
                printf("\n");
            }
            else{
                printf(" \\ " );
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
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
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                printf("\\ ");
                printf("\n");
            }
            else{
                printf("  \\ ");
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
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
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                printf("\\");
            }
            else{ 
                printf("\\ ");
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
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
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                testcolor4(j,compt+4,p);
                testcolor4(j,compt+5,p);
                testcolor4(j,compt+6,p);
                testcolor4(j,compt+7,p);
                testcolor4(j,compt+8,p);
                testcolor4(j,compt+9,p);
                testcolor4(j,compt+10,p);
                testcolor4(j,compt+11,p);
                testcolor4(j,compt+12,p);
                printf("/");
                printf("\n");
            }
            else{
                printf("  / ");
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                testcolor4(j,compt+4,p);
                testcolor4(j,compt+5,p);
                testcolor4(j,compt+6,p);
                testcolor4(j,compt+7,p);
                testcolor4(j,compt+8,p);
                testcolor4(j,compt+9,p);
                testcolor4(j,compt+10,p);
                testcolor4(j,compt+11,p);
                testcolor4(j,compt+12,p);
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
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                testcolor4(j,compt+4,p);
                testcolor4(j,compt+5,p);
                testcolor4(j,compt+6,p);
                testcolor4(j,compt+7,p);
                testcolor4(j,compt+8,p);
                testcolor4(j,compt+9,p);
                testcolor4(j,compt+10,p);
                testcolor4(j,compt+11,p);
                printf("/");
                printf("\n");
            }
            else{
                printf(" / ");
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                testcolor4(j,compt+4,p);
                testcolor4(j,compt+5,p);
                testcolor4(j,compt+6,p);
                testcolor4(j,compt+7,p);
                testcolor4(j,compt+8,p);
                testcolor4(j,compt+9,p);
                testcolor4(j,compt+10,p);
                testcolor4(j,compt+11,p);
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
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                testcolor4(j,compt+4,p);
                testcolor4(j,compt+5,p);
                testcolor4(j,compt+6,p);
                testcolor4(j,compt+7,p);
                testcolor4(j,compt+8,p);
                testcolor4(j,compt+9,p);
                testcolor4(j,compt+10,p);
                printf("/");
                printf("\n");
            }
            else{
                printf("/ ");
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                testcolor4(j,compt+4,p);
                testcolor4(j,compt+5,p);
                testcolor4(j,compt+6,p);
                testcolor4(j,compt+7,p);
                testcolor4(j,compt+8,p);
                testcolor4(j,compt+9,p);
                testcolor4(j,compt+10,p);
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
                testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                testcolor4(j,compt+4,p);
                testcolor4(j,compt+5,p);
                testcolor4(j,compt+6,p);
                testcolor4(j,compt+7,p);
                testcolor4(j,compt+8,p);
                testcolor4(j,compt+9,p);
                printf("/");
                printf("\n");
            }
            else{
                 printf(" / ");
                  testcolor4(j,compt,p);
                testcolor4(j,compt+1,p);
                testcolor4(j,compt+2,p);
                testcolor4(j,compt+3,p);
                testcolor4(j,compt+4,p);
                testcolor4(j,compt+5,p);
                testcolor4(j,compt+6,p);
                testcolor4(j,compt+7,p);
                testcolor4(j,compt+8,p);
                testcolor4(j,compt+9,p);
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
            testcolor4(j,compt,p);
            testcolor4(j,compt+1,p);
            testcolor4(j,compt+2,p);
            testcolor4(j,compt+3,p);
            testcolor4(j,compt+4,p);
            testcolor4(j,compt+5,p);
            testcolor4(j,compt+6,p);
            testcolor4(j,compt+7,p);
            testcolor4(j,compt+8,p);
            printf("|");
            printf("\n");
                
            compt+=9;
        }
    }
    printf("                   ---\n");
}
int recherchepion4(pions4 j[41],int equipe, char numero){
    int i;
    for(i=1;i<41;i++){
        if(j[i].equipe==equipe && j[i].nom==numero){
            return i;
        }
    }
}
void occupation4(cases4 p[122],pions4 j[41]){
    int i,k,temp=0;
    for(i=1;i<122;i++){
        temp=0;
        for(k=1;k<41;k++){
            if(p[i].nbcase==j[k].pcase){
                p[i].occupation=1;
                temp=1;
            }
            if( temp==0){
                p[i].occupation=0;
            }
        }
        //printf("la case %i est = %i \n",p[i].nbcase,p[i].occupation);
    }
}
int verfioccupation4(cases4 p[122],int n){
    int autorisation;
    if(p[n].occupation==0){
        autorisation=1;
    }
    else{
        autorisation=0;
    }
    return autorisation;
}
int dephg4(cases4 p[122],pions4 j[41],int pion){
    int erreur,n;
    if(j[pion].pcase==1||j[pion].pcase==2||j[pion].pcase==4||j[pion].pcase==7||j[pion].pcase==15||j[pion].pcase==14||j[pion].pcase==13||j[pion].pcase==12||j[pion].pcase==11||j[pion].pcase==20||j[pion].pcase==21||j[pion].pcase==22||j[pion].pcase==23||j[pion].pcase==66||j[pion].pcase==76||j[pion].pcase==87||j[pion].pcase==99){
        return 1;
    }
    if(j[pion].pcase==3&& p[1].occupation==0){
        p[j[pion].pcase].occupation=0;
        j[pion].pcase=1;
        p[j[pion].pcase].occupation=1;
        return 0;
    }
    if(j[pion].pcase==6||j[pion].pcase==5){
        n=j[pion].pcase;
        if(verfioccupation4(p,n-3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase<11&& j[pion].pcase>7){
        n=j[pion].pcase;
        if(verfioccupation4(p,n-4)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-4;
            p[j[pion].pcase].occupation=1;
            return 0;
        } 
        else{
            return 1;
        }
    }      
    if(j[pion].pcase<20 && j[pion].pcase>15){
        n=j[pion].pcase;
        if(verfioccupation4(p,n-9)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>23&&j[pion].pcase<36){
        if(verfioccupation4(p,j[pion].pcase-13)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>35 && j[pion].pcase<47){
        if(verfioccupation4(p,j[pion].pcase-12)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>46 && j[pion].pcase<57){
        if(verfioccupation4(p,j[pion].pcase-11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>56 && j[pion].pcase<66){
        if(verfioccupation4(p,j[pion].pcase-10)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>66 && j[pion].pcase<76){
        if(verfioccupation4(p,j[pion].pcase-10)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>76 && j[pion].pcase<87){
        if(verfioccupation4(p,j[pion].pcase-11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>87 && j[pion].pcase<99){
        if(verfioccupation4(p,j[pion].pcase-12)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>99 && j[pion].pcase<112){
        if(verfioccupation4(p,j[pion].pcase-13)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>111 && j[pion].pcase<116){
        if(verfioccupation4(p,j[pion].pcase-9)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>115 && j[pion].pcase<119){
        if(verfioccupation4(p,j[pion].pcase-4)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-4;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119 || j[pion].pcase==120){
        if(verfioccupation4(p,j[pion].pcase-3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==120){
        if(verfioccupation4(p,j[pion].pcase-2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
}int depbg4(cases4 p[122],pions4 j[41],int pion){
    int erreur;
    if(j[pion].pcase==1){
        if(verfioccupation4(p,2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verfioccupation4(p,j[pion].pcase+2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verfioccupation4(p,j[pion].pcase+2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=4&&j[pion].pcase<=6){
        if(verfioccupation4(p,j[pion].pcase+3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=7&&j[pion].pcase<=10){
        if(verfioccupation4(p,j[pion].pcase+8)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+8;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=11&&j[pion].pcase<=22){
        if(verfioccupation4(p,j[pion].pcase+12)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=24&&j[pion].pcase<=34){
        if(verfioccupation4(p,j[pion].pcase+11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=45){
        if(verfioccupation4(p,j[pion].pcase+10)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=55){
        if(verfioccupation4(p,j[pion].pcase+9)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verfioccupation4(p,j[pion].pcase+9)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=75){
        if(verfioccupation4(p,j[pion].pcase+10)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=98){
        if(verfioccupation4(p,j[pion].pcase+11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=103&&j[pion].pcase<=106){
        if(verfioccupation4(p,j[pion].pcase+8)){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+8;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=114){
        if(verfioccupation4(p,j[pion].pcase+3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==116||j[pion].pcase==117){
        if(verfioccupation4(p,j[pion].pcase+2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119){
        if(verfioccupation4(p,j[pion].pcase+1)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+1;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 1;
    }
}

int dephd4(cases4 p[122],pions4 j[41],int pion){
    int erreur;
    if(j[pion].pcase==1||j[pion].pcase==3||j[pion].pcase==6||j[pion].pcase==10||j[pion].pcase==11||j[pion].pcase==12||j[pion].pcase==13||j[pion].pcase==14||j[pion].pcase==20||j[pion].pcase==21||j[pion].pcase==22||j[pion].pcase==23||j[pion].pcase==19||j[pion].pcase==35||j[pion].pcase==46||j[pion].pcase==56||j[pion].pcase==75||j[pion].pcase==86||j[pion].pcase==98||j[pion].pcase==111){
        erreur=1;
    }
    if(j[pion].pcase==2){
        if(verfioccupation4(p,1)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=1;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==4||j[pion].pcase==5){
        if(verfioccupation4(p,j[pion].pcase-2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==7||j[pion].pcase==8||j[pion].pcase==9){
        if(verfioccupation4(p,j[pion].pcase-3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase<19&&j[pion].pcase>14){
        if(verfioccupation4(p,j[pion].pcase-8)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-8;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase<=35&&j[pion].pcase>=24){
        if(verfioccupation4(p,j[pion].pcase-12)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=46){
        if(verfioccupation4(p,j[pion].pcase-11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=56){
        if(verfioccupation4(p,j[pion].pcase-10)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verfioccupation4(p,j[pion].pcase-9)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=74){
        if(verfioccupation4(p,j[pion].pcase-9)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=76&&j[pion].pcase<=85){
        if(verfioccupation4(p,j[pion].pcase-10)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=97){
        if(verfioccupation4(p,j[pion].pcase-11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=99&&j[pion].pcase<=110){
        if(verfioccupation4(p,j[pion].pcase-12)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=115){
        if(verfioccupation4(p,j[pion].pcase-8)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-8;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=116&&j[pion].pcase<=118){
        if(verfioccupation4(p,j[pion].pcase-3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119||j[pion].pcase==120){
        if(verfioccupation4(p,j[pion].pcase-2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==120){
        if(verfioccupation4(p,j[pion].pcase-1)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-1;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    return 1;
}
int depbd4(cases4 p[122],pions4 j[41],int pion){
    int erreur;
    if(j[pion].pcase==1){
        if(verfioccupation4(p,j[pion].pcase+2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verfioccupation4(p,j[pion].pcase+3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verfioccupation4(p,j[pion].pcase+3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=4&&j[pion].pcase<=6){
        if(verfioccupation4(p,j[pion].pcase+4)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+4;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=7&&j[pion].pcase<=10){
        if(verfioccupation4(p,j[pion].pcase+9)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=11&&j[pion].pcase<=22){
        if(verfioccupation4(p,j[pion].pcase+13)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=24&&j[pion].pcase<=34){
        if(verfioccupation4(p,j[pion].pcase+12)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=45){
        if(verfioccupation4(p,j[pion].pcase+11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=55){
        if(verfioccupation4(p,j[pion].pcase+10)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verfioccupation4(p,j[pion].pcase+10)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=75){
        if(verfioccupation4(p,j[pion].pcase+11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=98){
        if(verfioccupation4(p,j[pion].pcase+12)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=103&&j[pion].pcase<=106){
        if(verfioccupation4(p,j[pion].pcase+9)){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=114){
        if(verfioccupation4(p,j[pion].pcase+4)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+4;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==116||j[pion].pcase==117){
        if(verfioccupation4(p,j[pion].pcase+3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119){
        if(verfioccupation4(p,j[pion].pcase+2)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 1;
    }
}

int deplacement4(cases4 p[122],pions4 j[41],int dep,int pion){
    int erreur=0;
    switch (dep)
    {
    case 1://deplacement4 vers la gauche
        if(p[j[pion].pcase-1].occupation==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-1;
            p[j[pion].pcase].occupation=1;
            erreur=0;
        }
        else{
            printf("Wait that's illegal\n");
            erreur=1;
        }
        return erreur;
        break;
    case 2 ://deplacement4 vers la droite
        if(p[j[pion].pcase+1].occupation==0){
        p[j[pion].pcase].occupation=0;
        j[pion].pcase=j[pion].pcase+1;
        p[j[pion].pcase].occupation=1;
    }
        break;
    case 3 ://deplacement4 haut gauche
        erreur=dephg4(p,j,pion);
        if(erreur==1){

        }
        break;
    case 4 ://deplacement4 haut droite
        erreur=dephd4(p,j,pion);
        break;
    case 5 ://deplacement4 bas gauche
        erreur=depbg4(p,j,pion);
        break;
    case 6 ://deplacement4 bas droite
        erreur=depbd4(p,j,pion);
        break;
    }
    return erreur;
}
void restaurationsauvegarde4(pions4 j[41]){
    printf("Fonctionnalite en beta, quelques bug peuvent survenir.\n");
    char name[128];
    int count=0,i;
    printf("Entrez nom de fichier :\n");
    scanf("%s", name); 
    FILE *fp = fopen(name, "r");
    if(fp == NULL){
        printf("Erreur \n");
    }
     for(i=0;i<36;i++){
    fscanf(fp,"%c %i %i %i\n", &j[i].nom, &j[i].equipe, &j[i].nbpion,&j[i].pcase); 
    }
}

void createsave4(pions4 j[41]){
    printf("Enregistrement en cours...\n");
    char name[128];
    int i;
    printf("Entrez nom de fichier : " );
    scanf("%s", name); 
    FILE *output = fopen(name, "w"); 
    if (!output) {
        printf("erreur\n");
    }
    for (i = 1; i < 41; i++) {
        //printf("Sauvegarde des elements\n");
        fprintf(output, "%c %i %i %i\n", j[i].nom,j[i].equipe,j[i].nbpion,j[i].pcase );

    }
    //printf("fermer document\n ");
    fclose(output); // close
}
void appelequipe4(int tour){
    if(tour==1) printf("Au tour de l'%cquipe bleu \n",130);
    if(tour==2) printf("Au tour de l'%cquipe rouge\n",130);
    if(tour==3) printf("Au tour de l'%cquipe blanc\n",130);
    if(tour==4) printf("Au tour de l'%cquipe jaune\n",130);
}
void Jeu4(){
    cases4 p[122];
    pions4 j[41];
    int erreur;
    reset4(p,j);
    saisiedefaut4(p,j,4);
    saisiecases4(p,j);
    affichage4(p,j);
    occupation4(p,j);
    int run=1,tour=1,temp,dep;
    char rep='0';
    while(run==1){
        appelequipe4(tour);
        //do{
            printf("Veuillez Entrer la case :\n");
            fflush(stdin);
            scanf("%c",&rep);
        //}while(rep!='1'||rep!='2'||rep!='3'||rep!='4'||rep!='5'||rep!='6'||rep!='7'||rep!='8'||rep!='9'||rep!='0');
        temp=recherchepion4(j,tour,rep);
        printf("Quel deplacement4 souhaitez vous faire ?\n");
        printf("Entrez 1 pour aller vers la gauche\nEntrez 2 pour aller vers la droite\nEntrez 3 pour monter a gauche\nEntrez 4 pour monter a droite\nEntrez 5 pour descendre a gauche\nEntrez 6 pour descendre a droite\n");
        do{
            scanf("%i",&dep);
            erreur=deplacement4(p,j,dep,temp);
            if(erreur==1){
                printf("Veuillez entrer un deplacement4 possible\n");
            }
        }while(dep>7||erreur==1);
        affichage4(p,j);
        if(tour<4){
            tour+=1;
        }
        else{
            tour=1;
        }
    }
}