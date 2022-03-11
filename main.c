#include <stdio.h>
#include<windows.h>
//Ce code est celui du jeu en affichage console.
typedef struct cases
{
    int nbcase;//Numéro de la case
    int equipe;//Equipe de la case, 0 si neutre
    int occupation;// Ocupation de la case 0/1
    char aff;//Affichage du pion "." si vide
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
    j[36].pcase=89;
    j[37].pcase=99;
    j[38].pcase=100;
    j[39].pcase=101;
    j[40].pcase=102;
    j[41].pcase=75;
    j[42].pcase=85;
    j[43].pcase=86;
    j[44].pcase=96;
    j[45].pcase=97;
    j[46].pcase=98;
    j[47].pcase=108;
    j[48].pcase=109;
    j[49].pcase=110;
    j[50].pcase=111;
    j[51].pcase=112;
    j[52].pcase=113;
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
cases* pionsgrille(cases p[122],pions j[61]){
    //Fonction permettant le remplacement de l'affichage des cases
    int i,z,temp=0,c=0;
    for(i=1;i<121;i++){
        temp=0;
        for(z=1;z<61;z++){
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
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int identification(pions j[61], cases p[122], int i){
    int z;
    for(z=1;z<61;z++){
        if(p[i].nbcase==j[z].pcase){
            return z;
            printf("Je suis rentre\n");
        }
    }
}
void testcolor(pions j[61],int i, cases p[122]){
    int z, temp=0;
    int couleur;
    z=identification(j,p,i);
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
        couleur=11;
        temp=1;
    }
    if(j[z].equipe==5){
        couleur=2;
        temp=1;
    }
    if(j[z].equipe==6){
        couleur=14;
        temp=1;
    }
    if(temp==1){
        Color(couleur,0);
        printf("%c ",j[z].nom);
        Color(15,0);
    }
    else{
        Color(15,0);
        printf(". ");
        Color(15,0);
    }
}
void affichage(cases p[122], pions j[60]){
    int l,compt=1;//variable représentant la ligne d'affichage
    int espace;
    printf("                   ---\n");
    p=pionsgrille(p,j);
    for(l=0;l<18;l++){
        if(l==1||l==17){
            for(espace=0;espace<9;espace++){
                printf("  ");
            }
            if(l==1){
                printf("/ ");
                testcolor(j,compt,p);
                printf("\\");
                printf("\n");
            }
            else{
                printf("\\ ");
                testcolor(j,compt,p);
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
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                printf("\\ ");
                printf("\n");
            }
            else{
                printf(" \\ " );
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
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
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                printf("\\ ");
                printf("\n");
            }
            else{
                printf("  \\ ");
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
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
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                printf("\\");
            }
            else{ 
                printf("\\ ");
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
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
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                testcolor(j,compt+4,p);
                testcolor(j,compt+5,p);
                testcolor(j,compt+6,p);
                testcolor(j,compt+7,p);
                testcolor(j,compt+8,p);
                testcolor(j,compt+9,p);
                testcolor(j,compt+10,p);
                testcolor(j,compt+11,p);
                testcolor(j,compt+12,p);
                printf("/");
                printf("\n");
            }
            else{
                printf("  / ");
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                testcolor(j,compt+4,p);
                testcolor(j,compt+5,p);
                testcolor(j,compt+6,p);
                testcolor(j,compt+7,p);
                testcolor(j,compt+8,p);
                testcolor(j,compt+9,p);
                testcolor(j,compt+10,p);
                testcolor(j,compt+11,p);
                testcolor(j,compt+12,p);
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
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                testcolor(j,compt+4,p);
                testcolor(j,compt+5,p);
                testcolor(j,compt+6,p);
                testcolor(j,compt+7,p);
                testcolor(j,compt+8,p);
                testcolor(j,compt+9,p);
                testcolor(j,compt+10,p);
                testcolor(j,compt+11,p);
                printf("/");
                printf("\n");
            }
            else{
                printf(" / ");
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                testcolor(j,compt+4,p);
                testcolor(j,compt+5,p);
                testcolor(j,compt+6,p);
                testcolor(j,compt+7,p);
                testcolor(j,compt+8,p);
                testcolor(j,compt+9,p);
                testcolor(j,compt+10,p);
                testcolor(j,compt+11,p);
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
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                testcolor(j,compt+4,p);
                testcolor(j,compt+5,p);
                testcolor(j,compt+6,p);
                testcolor(j,compt+7,p);
                testcolor(j,compt+8,p);
                testcolor(j,compt+9,p);
                testcolor(j,compt+10,p);
                printf("/");
                printf("\n");
            }
            else{
                printf("/ ");
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                testcolor(j,compt+4,p);
                testcolor(j,compt+5,p);
                testcolor(j,compt+6,p);
                testcolor(j,compt+7,p);
                testcolor(j,compt+8,p);
                testcolor(j,compt+9,p);
                testcolor(j,compt+10,p);
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
                testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                testcolor(j,compt+4,p);
                testcolor(j,compt+5,p);
                testcolor(j,compt+6,p);
                testcolor(j,compt+7,p);
                testcolor(j,compt+8,p);
                testcolor(j,compt+9,p);
                printf("/");
                printf("\n");
            }
            else{
                 printf(" / ");
                  testcolor(j,compt,p);
                testcolor(j,compt+1,p);
                testcolor(j,compt+2,p);
                testcolor(j,compt+3,p);
                testcolor(j,compt+4,p);
                testcolor(j,compt+5,p);
                testcolor(j,compt+6,p);
                testcolor(j,compt+7,p);
                testcolor(j,compt+8,p);
                testcolor(j,compt+9,p);
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
            testcolor(j,compt,p);
            testcolor(j,compt+1,p);
            testcolor(j,compt+2,p);
            testcolor(j,compt+3,p);
            testcolor(j,compt+4,p);
            testcolor(j,compt+5,p);
            testcolor(j,compt+6,p);
            testcolor(j,compt+7,p);
            testcolor(j,compt+8,p);
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
    printf("2 joueurs sur le m%cme ordinateur : tapez 2\n",136);
    printf("4 joueurs sur le m%cme ordinateur : tapez 4\n",136);
    printf("6 joueurs sur le m%cme ordinateur : tapez 6\n",136);
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
int recherchepion(pions j[61],int equipe, char numero){
    int i;
    for(i=1;i<61;i++){
        if(j[i].equipe==equipe && j[i].nom==numero){
            return i;
        }
    }
}
void occupation(cases p[122],pions j[61]){
    int i,k,temp=0;
    for(i=1;i<122;i++){
        temp=0;
        for(k=1;k<61;k++){
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
int verifoccupation(cases p[122],int n){
    int autorisation;
    if(p[n].occupation==0){
        autorisation=1;
    }
    else{
        autorisation=0;
    }
    return autorisation;
}
int dephg(cases p[122],pions j[61],int pion){
    int erreur,n;
    if(j[pion].pcase==1||j[pion].pcase==2||j[pion].pcase==4||j[pion].pcase==7||j[pion].pcase==15||j[pion].pcase==14||j[pion].pcase==13||j[pion].pcase==12||j[pion].pcase==11||j[pion].pcase==20||j[pion].pcase==21||j[pion].pcase==22||j[pion].pcase==23||j[pion].pcase==66||j[pion].pcase==76||j[pion].pcase==87||j[pion].pcase==99){
        return 1;
    }
    if(j[pion].pcase==3&& p[1].occupation==0){
        j[pion].pcase=1;
        return 0;
    }
    if(j[pion].pcase==6||j[pion].pcase==5){
        n=j[pion].pcase;
        if(verifoccupation(p,n-3)==1){
            j[pion].pcase=j[pion].pcase-3;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase<11&& j[pion].pcase>7){
        n=j[pion].pcase;
        if(verifoccupation(p,n-4)==1){
            j[pion].pcase=j[pion].pcase-4;
            return 0;
        } 
        else{
            return 1;
        }
    }      
    if(j[pion].pcase<20 && j[pion].pcase>15){
        n=j[pion].pcase;
        if(verifoccupation(p,n-9)==1){
            j[pion].pcase=j[pion].pcase-9;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>23&&j[pion].pcase<36){
        if(verifoccupation(p,j[pion].pcase-13)==1){
            j[pion].pcase=j[pion].pcase-13;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>35 && j[pion].pcase<47){
        if(verifoccupation(p,j[pion].pcase-12)==1){
            j[pion].pcase=j[pion].pcase-12;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>46 && j[pion].pcase<57){
        if(verifoccupation(p,j[pion].pcase-11)==1){
            j[pion].pcase=j[pion].pcase-11;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>56 && j[pion].pcase<66){
        if(verifoccupation(p,j[pion].pcase-10)==1){
            j[pion].pcase=j[pion].pcase-10;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>66 && j[pion].pcase<76){
        if(verifoccupation(p,j[pion].pcase-10)==1){
            j[pion].pcase=j[pion].pcase-10;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>76 && j[pion].pcase<87){
        if(verifoccupation(p,j[pion].pcase-11)==1){
            j[pion].pcase=j[pion].pcase-11;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>87 && j[pion].pcase<99){
        if(verifoccupation(p,j[pion].pcase-12)==1){
            j[pion].pcase=j[pion].pcase-12;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>99 && j[pion].pcase<112){
        if(verifoccupation(p,j[pion].pcase-13)==1){
            j[pion].pcase=j[pion].pcase-13;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>111 && j[pion].pcase<116){
        if(verifoccupation(p,j[pion].pcase-9)==1){
            j[pion].pcase=j[pion].pcase-9;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>115 && j[pion].pcase<119){
        if(verifoccupation(p,j[pion].pcase-4)==1){
            j[pion].pcase=j[pion].pcase-4;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119 || j[pion].pcase==120){
        if(verifoccupation(p,j[pion].pcase-3)==1){
            j[pion].pcase=j[pion].pcase-3;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==120){
        if(verifoccupation(p,j[pion].pcase-2)==1){
            j[pion].pcase=j[pion].pcase-2;
            return 0;
        }
        else{
            return 1;
        }
    }
}int depbg(cases p[61],pions j[61],int pion){
    int erreur;
    if(j[pion].pcase==1){
        if(verifoccupation(p,2)==1){
            j[pion].pcase=j[pion].pcase+2;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation(p,j[pion].pcase+2)==1){
            j[pion].pcase=j[pion].pcase+2;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation(p,j[pion].pcase+2)==1){
            j[pion].pcase=j[pion].pcase+2;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=4&&j[pion].pcase<=6){
        if(verifoccupation(p,j[pion].pcase+3)==1){
            j[pion].pcase=j[pion].pcase+3;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=7&&j[pion].pcase<=10){
        if(verifoccupation(p,j[pion].pcase+8)==1){
            j[pion].pcase=j[pion].pcase+8;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=11&&j[pion].pcase<=22){
        if(verifoccupation(p,j[pion].pcase+12)==1){
            j[pion].pcase=j[pion].pcase+12; 
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=24&&j[pion].pcase<=34){
        if(verifoccupation(p,j[pion].pcase+11)==1){
            j[pion].pcase=j[pion].pcase+11;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=45){
        if(verifoccupation(p,j[pion].pcase+10)==1){
            j[pion].pcase=j[pion].pcase+10;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=55){
        if(verifoccupation(p,j[pion].pcase+9)==1){
            j[pion].pcase=j[pion].pcase+9;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation(p,j[pion].pcase+9)==1){
            j[pion].pcase=j[pion].pcase+9; 
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=75){
        if(verifoccupation(p,j[pion].pcase+10)==1){
            j[pion].pcase=j[pion].pcase+10;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=98){
        if(verifoccupation(p,j[pion].pcase+11)==1){
            j[pion].pcase=j[pion].pcase+11;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=103&&j[pion].pcase<=106){
        if(verifoccupation(p,j[pion].pcase+8)){
            j[pion].pcase=j[pion].pcase+8;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=114){
        if(verifoccupation(p,j[pion].pcase+3)==1){
            j[pion].pcase=j[pion].pcase+3; 
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==116||j[pion].pcase==117){
        if(verifoccupation(p,j[pion].pcase+2)==1){
            j[pion].pcase=j[pion].pcase+2;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119){
        if(verifoccupation(p,j[pion].pcase+1)==1){
            j[pion].pcase=j[pion].pcase+1;
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

int dephd(cases p[122],pions j[61],int pion){
    int erreur;
    if(j[pion].pcase==1||j[pion].pcase==3||j[pion].pcase==6||j[pion].pcase==10||j[pion].pcase==11||j[pion].pcase==12||j[pion].pcase==13||j[pion].pcase==14||j[pion].pcase==20||j[pion].pcase==21||j[pion].pcase==22||j[pion].pcase==23||j[pion].pcase==19||j[pion].pcase==35||j[pion].pcase==46||j[pion].pcase==56||j[pion].pcase==75||j[pion].pcase==86||j[pion].pcase==98||j[pion].pcase==111){
        erreur=1;
    }
    if(j[pion].pcase==2){
        if(verifoccupation(p,1)==1){
            j[pion].pcase=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==4||j[pion].pcase==5){
        if(verifoccupation(p,j[pion].pcase-2)==1){
            j[pion].pcase=j[pion].pcase-2;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==7||j[pion].pcase==8||j[pion].pcase==9){
        if(verifoccupation(p,j[pion].pcase-3)==1){
            j[pion].pcase=j[pion].pcase-3;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase<19&&j[pion].pcase>14){
        if(verifoccupation(p,j[pion].pcase-8)==1){
            j[pion].pcase=j[pion].pcase-8;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase<=35&&j[pion].pcase>=24){
        if(verifoccupation(p,j[pion].pcase-12)==1){
            j[pion].pcase=j[pion].pcase-12;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=46){
        if(verifoccupation(p,j[pion].pcase-11)==1){
            j[pion].pcase=j[pion].pcase-11;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=56){
        if(verifoccupation(p,j[pion].pcase-10)==1){
            j[pion].pcase=j[pion].pcase-10;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation(p,j[pion].pcase-9)==1){
            j[pion].pcase=j[pion].pcase-9;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=74){
        if(verifoccupation(p,j[pion].pcase-9)==1){
            j[pion].pcase=j[pion].pcase-9;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=76&&j[pion].pcase<=85){
        if(verifoccupation(p,j[pion].pcase-10)==1){
            j[pion].pcase=j[pion].pcase-10;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=97){
        if(verifoccupation(p,j[pion].pcase-11)==1){
            j[pion].pcase=j[pion].pcase-11;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=99&&j[pion].pcase<=110){
        if(verifoccupation(p,j[pion].pcase-12)==1){
            j[pion].pcase=j[pion].pcase-12;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=115){
        if(verifoccupation(p,j[pion].pcase-8)==1){
            j[pion].pcase=j[pion].pcase-8;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=116&&j[pion].pcase<=118){
        if(verifoccupation(p,j[pion].pcase-3)==1){
            j[pion].pcase=j[pion].pcase-3;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119||j[pion].pcase==120){
        if(verifoccupation(p,j[pion].pcase-2)==1){
            j[pion].pcase=j[pion].pcase-2;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==120){
        if(verifoccupation(p,j[pion].pcase-1)==1){
            j[pion].pcase=j[pion].pcase-1;
            return 0;
        }
        else{
            return 1;
        }
    }
    return 1;
}
int depbd(cases p[61],pions j[61],int pion){
    int erreur;
    if(j[pion].pcase==1){
        if(verifoccupation(p,j[pion].pcase+2)==1){
            j[pion].pcase=j[pion].pcase+2;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation(p,j[pion].pcase+3)==1){
            j[pion].pcase=j[pion].pcase+3;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation(p,j[pion].pcase+3)==1){
            j[pion].pcase=j[pion].pcase+3;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=4&&j[pion].pcase<=6){
        if(verifoccupation(p,j[pion].pcase+4)==1){
            j[pion].pcase=j[pion].pcase+4;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=7&&j[pion].pcase<=10){
        if(verifoccupation(p,j[pion].pcase+9)==1){
            j[pion].pcase=j[pion].pcase+9;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=11&&j[pion].pcase<=22){
        if(verifoccupation(p,j[pion].pcase+13)==1){
            j[pion].pcase=j[pion].pcase+13; 
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=24&&j[pion].pcase<=34){
        if(verifoccupation(p,j[pion].pcase+12)==1){
            j[pion].pcase=j[pion].pcase+12;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=45){
        if(verifoccupation(p,j[pion].pcase+11)==1){
            j[pion].pcase=j[pion].pcase+11;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=55){
        if(verifoccupation(p,j[pion].pcase+10)==1){
            j[pion].pcase=j[pion].pcase+10;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation(p,j[pion].pcase+10)==1){
            j[pion].pcase=j[pion].pcase+10; 
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=75){
        if(verifoccupation(p,j[pion].pcase+11)==1){
            j[pion].pcase=j[pion].pcase+11;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=98){
        if(verifoccupation(p,j[pion].pcase+12)==1){
            j[pion].pcase=j[pion].pcase+12;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=103&&j[pion].pcase<=106){
        if(verifoccupation(p,j[pion].pcase+9)){
            j[pion].pcase=j[pion].pcase+9;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=114){
        if(verifoccupation(p,j[pion].pcase+4)==1){
            j[pion].pcase=j[pion].pcase+4; 
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==116||j[pion].pcase==117){
        if(verifoccupation(p,j[pion].pcase+3)==1){
            j[pion].pcase=j[pion].pcase+3;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119){
        if(verifoccupation(p,j[pion].pcase+2)==1){
            j[pion].pcase=j[pion].pcase+2;
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
int deplacement(cases p[122],pions j[61],int dep,int pion){
    int erreur=0;
    switch (dep)
    {
    case 1://deplacement vers la gauche
        if(p[j[pion].pcase-1].occupation==0){
            j[pion].pcase=j[pion].pcase-1;
            erreur=0;
        }
        else{
            printf("Wait that's illegal\n");
            erreur=1;
        }
        return erreur;
        break;
    case 2 ://deplacement vers la droite
        if(p[j[pion].pcase+1].occupation==0){
        j[pion].pcase=j[pion].pcase+1;
    }
        break;
    case 3 ://deplacement haut gauche
        erreur=dephg(p,j,pion);
        break;
    case 4 ://deplacement haut droite
        erreur=dephd(p,j,pion);
        break;
    case 5 ://deplacement bas gauche
        erreur=depbg(p,j,pion);
        break;
    case 6 ://deplacement bas droite
        erreur=depbd(p,j,pion);
        break;
    }
    return erreur;
}
void restaurationsauvegarde(pions j[61]){
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

void createsave(pions j[61]){
    printf("Enregistrement en cours...\n");
    char name[128];
    int i;
    printf("Entrez nom de fichier : " );
    scanf("%s", name); 
    FILE *output = fopen(name, "w"); 
    if (!output) {
        printf("erreur\n");
    }
    for (i = 1; i < 61; i++) {
        //printf("Sauvegarde des elements\n");
        fprintf(output, "%c %i %i %i\n", j[i].nom,j[i].equipe,j[i].nbpion,j[i].pcase );

    }
    //printf("fermer document\n ");
    fclose(output); // close
}
void Jeu(cases p[122], pions j[61]){
    int erreur;
    affichage(p,j);
    occupation(p,j);
    int run=1,tour=2,temp,dep;
    char rep='0';
    while(run==1){
        printf("Au tour de l'equipe %i !\n",tour);
        //do{
            printf("Veuillez Entrer la case :\n");
            fflush(stdin);
            scanf("%c",&rep);
        //}while(rep!='1'||rep!='2'||rep!='3'||rep!='4'||rep!='5'||rep!='6'||rep!='7'||rep!='8'||rep!='9'||rep!='0');
        temp=recherchepion(j,tour,rep);
        printf("Quel deplacement souhaitez vous faire ?\n");
        printf("Entrez 1 pour aller vers la gauche\nEntrez 2 pour aller vers la droite\nEntrez 3 pour monter a gauche\nEntrez 4 pour monter a droite\nEntrez 5 pour descendre a gauche\nEntrez 6 pour descendre a droite\n");
        do{
            scanf("%i",&dep);
            erreur=deplacement(p,j,dep,temp);
            if(erreur==1){
                printf("Veuillez entrer un deplacement possible\n");
            }
        }while(dep>7||erreur==1);
        affichage(p,j);
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
    //affichage(plateau,joueurs);
    Jeu(plateau,joueurs);
    return 0;
}