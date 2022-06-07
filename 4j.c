#include <stdio.h>
#include<windows.h>
//Ce code est celui du jeu en affichage console.
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
    int win;
}pions4;
void attpion4(cases4 p[122], pions4 j[41]);
int sauthd4(cases4 p[122],pions4 j[41],int pion);
int sauthg4(cases4 p[122],pions4 j[41],int pion);
int sautbg4(cases4 p[122],pions4 j[41],int pion);
int sautbd4(cases4 p[122],pions4 j[41],int pion);
int saut4(cases4 p[122],pions4 j[41],int pion,int dep);
//Fonction permettant la réinitialisation du jeu et appelée au début pour remettre à 0 chaques variables
void resetplateau4(cases4 p[122]){
    int i;
    for(i=0;i<122;i++){
        p[i].nbcase=0;
        p[i].equipe=0;
        p[i].occupation=0;
        p[i].aff='.';
    }
}
void reset4(pions4 j[41]){
    int i;
    for(i=0;i<41;i++){
        j[i].nbpion=i;
        j[i].equipe=0;
        j[i].nom='0';
        j[i].pcase=0;
        j[i].win=0;
    }
    //printf("Toutes les cases4 ont ete reinitialisee corectement !\n");
}
void saisiecases4(cases4 p[122], pions4 j[41]){
    //cette fonciton saisie par défaut les cases pour un début de partie.
    int i;
    for(i=1;i<122;i++){
        p[i].nbcase=i;
        //printf("%i, ",p[i].nbcase);
    }
    attpion4(p,j);
}
void base4(cases4 p[122]){
    int i;
    //Equipe Bleu
    for(i=1;i<10;i++){
        p[i].equipe=1;
    }
    //Equipe Rouge
    for(i=11;i<14;i++){
        p[i].equipe=2;
    }
    p[24].equipe=2;
    p[25].equipe=2;
    p[26].equipe=2;
    p[36].equipe=2;
    p[37].equipe=2;
    p[47].equipe=2;
    //Equipe Blanche
    for(i=20;i<23;i++){
        p[i].equipe=3;
    }
    p[33].equipe=3;
    p[34].equipe=3;
    p[35].equipe=3;
    p[45].equipe=3;
    p[46].equipe=3;
    p[56].equipe=3;
    //Equipe Cyan
    for(i=99;i<102;i++){
        p[i].equipe=4;
    }
    p[66].equipe=4;
    p[76].equipe=4;
    p[77].equipe=4;
    p[87].equipe=4;
    p[88].equipe=4;
    p[89].equipe=4;
    //Equipe Verte
    for(i=108;i<111;i++){
        p[i].equipe=5;
    }
    p[75].equipe=5;
    p[85].equipe=5;
    p[86].equipe=5;
    p[96].equipe=5;
    p[97].equipe=5;
    p[98].equipe=5;
    //Equipe jaune
    for(i=112;i<121;i++){
        p[i].equipe=6;
    }
}
void saisiedefaut4(cases4 p[122],pions4 j[41]){
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
            else{
                printf("");
            }
        }
    }
    printf("\n");
    base4(p);
}
void test4(cases4 p[122], pions4 j[41]){
    int i;
    printf("Affichage liste joueurs\n");
    for(i=0;i<41;i++){
        printf("Numero de pion : %i  || Numero de case : %i  || equipe : %i  || nom : %c\n",j[i].nbpion,j[i].pcase,j[i].equipe,j[i].nom);
    }
}
cases4* pionsgrille4(cases4 p[122],pions4 j[41]){
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
        }
    }
    return 255;
}
void testcolor4(pions4 j[41],int i, cases4 p[122]){
    int z, temp=0;
    int couleur;
    z=identification4(j,p,i);
    if(z==255){
        Color2(15,0);
        printf(". ");
        Color2(15,0);
        temp=3;
    }
    if(j[z].equipe==1&&temp==0){
        couleur=1;
        temp=1;
    }
    if(j[z].equipe==2&&temp==0){
        couleur=4;
        temp=1;
    }
    if(j[z].equipe==3&&temp==0){
        couleur=15;
        temp=1;
    }
    if(j[z].equipe==4&&temp==0){
        couleur=11;
        temp=1;
    }
    if(j[z].equipe==5&&temp==0){
        couleur=2;
        temp=1;
    }
    if(j[z].equipe==6&&temp==0){
        couleur=14;
        temp=1;
    }
    if(temp==1){
        Color4(couleur,0&&temp==0);
        printf("%c ",j[z].nom);
        Color4(15,0);
    }
}
void affichage4(cases4 p[122], pions4 j[41]){
    int l,compt=1;//variable représentant la ligne d'affichage
    int espace;
    printf("                   ---\n");
    p=pionsgrille4(p,j);
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
int verifoccupation4(cases4 p[122],int n){
    int autorisation;
    if(p[n].occupation==0){
        autorisation=1;
    }
    else{
        autorisation=0;
    }
    return autorisation;
}
int dephg4(cases4 p[122],pions4 j[41],int pion,int exesaut){
    int erreur,n;
    if(j[pion].pcase==1||j[pion].pcase==2||j[pion].pcase==4||j[pion].pcase==7||j[pion].pcase==15||j[pion].pcase==14||j[pion].pcase==13||j[pion].pcase==12||j[pion].pcase==11||j[pion].pcase==20||j[pion].pcase==21||j[pion].pcase==22||j[pion].pcase==23||j[pion].pcase==66||j[pion].pcase==76||j[pion].pcase==87||j[pion].pcase==99){
        return 1;
    }
    if(j[pion].pcase==3&& p[1].occupation==0&&exesaut==0){
        p[j[pion].pcase].occupation=0;
        j[pion].pcase=1;
        p[j[pion].pcase].occupation=1;
        return 0;
    }
    else{
        if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==6||j[pion].pcase==5){
        n=j[pion].pcase;
        if(verifoccupation4(p,n-3)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase<11&& j[pion].pcase>7){
        n=j[pion].pcase;
        if(verifoccupation4(p,n-4)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-4;
            p[j[pion].pcase].occupation=1;
            return 0;
        } 
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    else{
        erreur=1;
    }      
    if(j[pion].pcase<20 && j[pion].pcase>15){
        n=j[pion].pcase;
        if(verifoccupation4(p,n-9)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    else{
        erreur=1;
    }
    if(j[pion].pcase>23&&j[pion].pcase<36){
        if(verifoccupation4(p,j[pion].pcase-13)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>35 && j[pion].pcase<47){
        if(verifoccupation4(p,j[pion].pcase-12)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>46 && j[pion].pcase<57){
        if(verifoccupation4(p,j[pion].pcase-11)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
        }
    }
    if(j[pion].pcase>56 && j[pion].pcase<66){
        if(verifoccupation4(p,j[pion].pcase-10)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>66 && j[pion].pcase<76&&exesaut==0){
        if(verifoccupation4(p,j[pion].pcase-10)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>76 && j[pion].pcase<87){
        if(verifoccupation4(p,j[pion].pcase-11)&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>87 && j[pion].pcase<99){
        if(verifoccupation4(p,j[pion].pcase-12)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>99 && j[pion].pcase<112){
        if(verifoccupation4(p,j[pion].pcase-13)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    else{
        erreur=1;
    }
    if(j[pion].pcase>111 && j[pion].pcase<116){
        if(verifoccupation4(p,j[pion].pcase-9)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>115 && j[pion].pcase<119){
        if(verifoccupation4(p,j[pion].pcase-4)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-4;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase==119 || j[pion].pcase==120){
        if(verifoccupation4(p,j[pion].pcase-3)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase==120){
        if(verifoccupation4(p,j[pion].pcase-2)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    return erreur;
}
int depbg(cases4 p[41],pions4 j[41],int pion,int exesaut){
    int erreur;
    if(j[pion].pcase==1){
        if(verifoccupation4(p,2)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation4(p,j[pion].pcase+2)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation4(p,j[pion].pcase+2)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=4&&j[pion].pcase<=6){
        if(verifoccupation4(p,j[pion].pcase+3)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=7&&j[pion].pcase<=10){
        if(verifoccupation4(p,j[pion].pcase+8)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+8;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=11&&j[pion].pcase<=22){
        if(verifoccupation4(p,j[pion].pcase+12)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=24&&j[pion].pcase<=34){
        if(verifoccupation4(p,j[pion].pcase+11)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=45){
        if(verifoccupation4(p,j[pion].pcase+10)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=55){
        if(verifoccupation4(p,j[pion].pcase+9)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation4(p,j[pion].pcase+9)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=75){
        if(verifoccupation4(p,j[pion].pcase+10)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=98){
        if(verifoccupation4(p,j[pion].pcase+11)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=103&&j[pion].pcase<=106){
        if(verifoccupation4(p,j[pion].pcase+8)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+8;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=114){
        if(verifoccupation4(p,j[pion].pcase+3)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase==116||j[pion].pcase==117){
        if(verifoccupation4(p,j[pion].pcase+2)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    if(j[pion].pcase==119){
        if(verifoccupation4(p,j[pion].pcase+1)==1&&exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+1;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
            return 2;
        }
        else{
            return 1;
        }
        }
    }
    else{
        return 1;
    }
}
int dephd(cases4 p[122],pions4 j[41],int pion, int exesaut){
    int erreur;
    if(j[pion].pcase==1||j[pion].pcase==3||j[pion].pcase==6||j[pion].pcase==10||j[pion].pcase==11||j[pion].pcase==12||j[pion].pcase==13||j[pion].pcase==14||j[pion].pcase==20||j[pion].pcase==21||j[pion].pcase==22||j[pion].pcase==23||j[pion].pcase==19||j[pion].pcase==35||j[pion].pcase==46||j[pion].pcase==56||j[pion].pcase==75||j[pion].pcase==86||j[pion].pcase==98||j[pion].pcase==111){
        erreur=1;
    }
    if(j[pion].pcase==2){
        if(verifoccupation4(p,1)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=1;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase==4||j[pion].pcase==5){
        if(verifoccupation4(p,j[pion].pcase-2)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase==7||j[pion].pcase==8||j[pion].pcase==9){
        if(verifoccupation4(p,j[pion].pcase-3)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase<19&&j[pion].pcase>14){
        if(verifoccupation4(p,j[pion].pcase-8)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-8;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase<=35&&j[pion].pcase>=24){
        if(verifoccupation4(p,j[pion].pcase-12)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=46){
        if(verifoccupation4(p,j[pion].pcase-11)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=56){
        if(verifoccupation4(p,j[pion].pcase-10)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation4(p,j[pion].pcase-9)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=74){
        if(verifoccupation4(p,j[pion].pcase-9)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=76&&j[pion].pcase<=85){
        if(verifoccupation4(p,j[pion].pcase-10)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=97){
        if(verifoccupation4(p,j[pion].pcase-11)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=99&&j[pion].pcase<=110){
        if(verifoccupation4(p,j[pion].pcase-12)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=115){
        if(verifoccupation4(p,j[pion].pcase-8)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-8;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=116&&j[pion].pcase<=118){
        if(verifoccupation4(p,j[pion].pcase-3)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase==119||j[pion].pcase==120){
        if(verifoccupation4(p,j[pion].pcase-2)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase==120){
        if(verifoccupation4(p,j[pion].pcase-1)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-1;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    return 1;
}
int depbd(cases4 p[122],pions4 j[41],int pion,int exesaut){
    int erreur;
    if(j[pion].pcase==1){
        if(verifoccupation4(p,j[pion].pcase+2)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation4(p,j[pion].pcase+3)==1&& exesaut==0 ){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation4(p,j[pion].pcase+3)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
                return 2;
            }
            else{
            return 1;
            }
        }
    }
    if(j[pion].pcase>=4&&j[pion].pcase<=6){
        if(verifoccupation4(p,j[pion].pcase+4)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+4;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }      
    }
    if(j[pion].pcase>=7&&j[pion].pcase<=10){
        if(verifoccupation4(p,j[pion].pcase+9)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=11&&j[pion].pcase<=22){
        if(verifoccupation4(p,j[pion].pcase+13)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    
    if(j[pion].pcase>=24&&j[pion].pcase<=34){
        if(verifoccupation4(p,j[pion].pcase+12)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=45){
        if(verifoccupation4(p,j[pion].pcase+11)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=55){
        if(verifoccupation4(p,j[pion].pcase+10)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation4(p,j[pion].pcase+10)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+10;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=75){
        if(verifoccupation4(p,j[pion].pcase+11)==1 && exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=98){
        if(verifoccupation4(p,j[pion].pcase+12)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+12;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=103&&j[pion].pcase<=106){
        if(verifoccupation4(p,j[pion].pcase+9)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+9;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=114){
        if(verifoccupation4(p,j[pion].pcase+4)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+4;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase==116||j[pion].pcase==117){
        if(verifoccupation4(p,j[pion].pcase+3)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    if(j[pion].pcase==119){
        if(verifoccupation4(p,j[pion].pcase+2)==1&& exesaut==0){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
             if(exesaut==1){
                return 2;
            }
            else{
                return 1;
            }
        }
    }
    else{
        return 1;
    }
}
int sauthg(cases4 p[122],pions4 j[41],int pion){
    int erreur,n;
    if(j[pion].pcase==1||j[pion].pcase==2||j[pion].pcase==4||j[pion].pcase==7||j[pion].pcase==15||j[pion].pcase==14||j[pion].pcase==13||j[pion].pcase==12||j[pion].pcase==11||j[pion].pcase==20||j[pion].pcase==21||j[pion].pcase==22||j[pion].pcase==23||j[pion].pcase==66||j[pion].pcase==76||j[pion].pcase==87||j[pion].pcase==99){
        return 1;
    }
    if(j[pion].pcase==6){
        n=j[pion].pcase;
        if(verifoccupation4(p,n-5)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-5;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==10||j[pion].pcase==9){
        n=j[pion].pcase;
        if(verifoccupation4(p,n-7)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-7;
            p[j[pion].pcase].occupation=1;
            return 0;
        } 
        else{
            return 1;
        }
    }      
    if(j[pion].pcase<20 && j[pion].pcase>16){
        n=j[pion].pcase;
        if(verifoccupation4(p,n-13)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>28&&j[pion].pcase<33){
        if(verifoccupation4(p,j[pion].pcase-22)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-22;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>35 && j[pion].pcase<47){
        if(verifoccupation4(p,j[pion].pcase-25)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-25;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>46 && j[pion].pcase<57){
        if(verifoccupation4(p,j[pion].pcase-23)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-23;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>56 && j[pion].pcase<66){
        if(verifoccupation4(p,j[pion].pcase-21)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-21;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>66 && j[pion].pcase<76){
        if(verifoccupation4(p,j[pion].pcase-20)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-20;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>77 && j[pion].pcase<87){
        if(verifoccupation4(p,j[pion].pcase-21)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-21;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>88 && j[pion].pcase<99){
        if(verifoccupation4(p,j[pion].pcase-23)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-23;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>100 && j[pion].pcase<112){
        if(verifoccupation4(p,j[pion].pcase-25)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-25;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>111 && j[pion].pcase<116){
        if(verifoccupation4(p,j[pion].pcase-22)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-22;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>115 && j[pion].pcase<119){
        if(verifoccupation4(p,j[pion].pcase-13)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119 || j[pion].pcase==120){
        if(verifoccupation4(p,j[pion].pcase-6)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-6;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==120){
        if(verifoccupation4(p,j[pion].pcase-4)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-4;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
}
int sauthd(cases4 p[122],pions4 j[41],int pion){
    int erreur;
    if(j[pion].pcase==1||j[pion].pcase==3||j[pion].pcase==6||j[pion].pcase==10||j[pion].pcase==11||j[pion].pcase==12||j[pion].pcase==13||j[pion].pcase==14||j[pion].pcase==20||j[pion].pcase==21||j[pion].pcase==22||j[pion].pcase==23||j[pion].pcase==19||j[pion].pcase==35||j[pion].pcase==46||j[pion].pcase==56||j[pion].pcase==75||j[pion].pcase==86||j[pion].pcase==98||j[pion].pcase==111){
        erreur=1;
    }
    if(j[pion].pcase==4){
        if(verifoccupation4(p,j[pion].pcase-3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==7||j[pion].pcase==8){
        if(verifoccupation4(p,j[pion].pcase-5)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-5;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase<18&&j[pion].pcase>14){
        if(verifoccupation4(p,j[pion].pcase-11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase<=30&&j[pion].pcase>27){
        if(verifoccupation4(p,j[pion].pcase-20)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-20;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=46){
        if(verifoccupation4(p,j[pion].pcase-23)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-23;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=56){
        if(verifoccupation4(p,j[pion].pcase-21)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-21;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation4(p,j[pion].pcase-19)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-19;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=74){
        if(verifoccupation4(p,j[pion].pcase-18)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-18;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=76&&j[pion].pcase<=84){
        if(verifoccupation4(p,j[pion].pcase-19)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-19;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=96){
        if(verifoccupation4(p,j[pion].pcase-21)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-21;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=99&&j[pion].pcase<=109){
        if(verifoccupation4(p,j[pion].pcase-23)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-23;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=112&&j[pion].pcase<=115){
        if(verifoccupation4(p,j[pion].pcase-20)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-20;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=116&&j[pion].pcase<=118){
        if(verifoccupation4(p,j[pion].pcase-11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==119||j[pion].pcase==120){
        if(verifoccupation4(p,j[pion].pcase-5)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-5;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==120){
        if(verifoccupation4(p,j[pion].pcase-3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-3;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    return 1;
}
int sautbd(cases4 p[122],pions4 j[41],int pion){
    if(j[pion].pcase==1){
        if(verifoccupation4(p,j[pion].pcase+5)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+5;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==2||j[pion].pcase==3){
        if(verifoccupation4(p,j[pion].pcase+7)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+7;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=4&&j[pion].pcase<=6){
        if(verifoccupation4(p,j[pion].pcase+13)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=7&&j[pion].pcase<=10){
        if(verifoccupation4(p,j[pion].pcase+22)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+22;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=11&&j[pion].pcase<=21){
        if(verifoccupation4(p,j[pion].pcase+25)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+25;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=24&&j[pion].pcase<=33){
        if(verifoccupation4(p,j[pion].pcase+23)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+23;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=36&&j[pion].pcase<=44){
        if(verifoccupation4(p,j[pion].pcase+21)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+21;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=47&&j[pion].pcase<=55){
        if(verifoccupation4(p,j[pion].pcase+20)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+20;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation4(p,j[pion].pcase+21)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+21;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=75){
        if(verifoccupation4(p,j[pion].pcase+23)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+23;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=87&&j[pion].pcase<=86){
        if(verifoccupation4(p,j[pion].pcase+25)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+25;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=103&&j[pion].pcase<=105){
        if(verifoccupation4(p,j[pion].pcase+13)){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+13;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==112||j[pion].pcase==113){
        if(verifoccupation4(p,j[pion].pcase+7)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+7;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==116){
        if(verifoccupation4(p,j[pion].pcase+3)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+5;
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
int sautbg(cases4 p[122],pions4 j[41],int pion){
    int erreur;
    if(j[pion].pcase==1){
        if(verifoccupation4(p,j[pion].pcase+3)==1){
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
        if(verifoccupation4(p,j[pion].pcase+5)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+5;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=4&&j[pion].pcase<=6){
        if(verifoccupation4(p,j[pion].pcase+11)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=7&&j[pion].pcase<=10){
        if(verifoccupation4(p,j[pion].pcase+20)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+20;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=13&&j[pion].pcase<=23){
        if(verifoccupation4(p,j[pion].pcase+23)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+23;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=26&&j[pion].pcase<=35){
        if(verifoccupation4(p,j[pion].pcase+21)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+21;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=38&&j[pion].pcase<=46){
        if(verifoccupation4(p,j[pion].pcase+19)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+19;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=48&&j[pion].pcase<=56){
        if(verifoccupation4(p,j[pion].pcase+18)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+18;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=57&&j[pion].pcase<=65){
        if(verifoccupation4(p,j[pion].pcase+19)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+19;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=66&&j[pion].pcase<=75){
        if(verifoccupation4(p,j[pion].pcase+21)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+21;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=76&&j[pion].pcase<=86){
        if(verifoccupation4(p,j[pion].pcase+23)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+23;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=92&&j[pion].pcase<=95){
        if(verifoccupation4(p,j[pion].pcase+20)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+20;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=105&&j[pion].pcase<=107){
        if(verifoccupation4(p,j[pion].pcase+11)){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+11;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase>=114&&j[pion].pcase<=115){
        if(verifoccupation4(p,j[pion].pcase+5)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+5;
            p[j[pion].pcase].occupation=1;
            return 0;
        }
        else{
            return 1;
        }
    }
    if(j[pion].pcase==118){
        if(verifoccupation4(p,j[pion].pcase+1)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+3;
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
int antisaut4(cases4 p[122],pions4 j[41],int pion,int dep){
    int interdit[17];
    interdit[0]=1;
    interdit[1]=2;
    interdit[2]=4;
    interdit[3]=7;
    interdit[4]=11;
    interdit[5]=24;
    interdit[6]=36;
    interdit[7]=47;
    interdit[8]=57;
    interdit[9]=66;
    interdit[10]=76;
    interdit[11]=87;
    interdit[12]=99;
    interdit[13]=112;
    interdit[14]=116;
    interdit[15]=119;
    interdit[16]=121;
    int interditd[17];
    interdit[0]=3;
    interdit[1]=6;
    interdit[2]=10;
    interdit[3]=23;
    interdit[4]=35;
    interdit[5]=46;
    interdit[6]=56;
    interdit[7]=65;
    interdit[8]=75;
    interdit[9]=86;
    interdit[10]=98;
    interdit[11]=111;
    interdit[12]=115;
    interdit[13]=118;
    interdit[14]=120;
    interdit[15]=121;
    interdit[16]=1;
    if(dep==1){
        for(int i=0;i<31;i++){
            if(pion==interdit[i]){
                return 0;
            }
        }
        return 1;
    }
    if(dep==2){
        for(int i=0;i<31;i++){
            if(pion==interdit[i]){
                return 0;
            }
        }
        return 1;
    }
}
int enchainement4(cases4 p[122],pions4 j[41],int pion,int dep,int exesaut){
    int erreur; 
    switch (dep)
        {
        case 1://deplacement vers la gauche
            if(p[j[pion].pcase-1].occupation==0){
                printf("Deplacement impossible, ceci n'est pas un saut\n");
                return 0;
                //printf(" %i \n %i \n",j[pion].pcase, p[j[pion].pcase].occupation);
                //printf(" %i \n %i \n",j[pion].pcase, p[j[pion].pcase].occupation);
            }
            else{
                if(p[j[pion].pcase-2].occupation==0&&antisaut4(p,j,pion,dep)==1){
                    p[j[pion].pcase].occupation=0;
                    j[pion].pcase=j[pion].pcase-2;
                    p[j[pion].pcase].occupation=1;
                    return 1;
                }
                else{
                    printf("Erreur deplacmenet impossible\n");
                    return 0;
                }
            }
            break;
        case 2 ://deplacement vers la droite
            if(p[j[pion].pcase+1].occupation==0&&antisaut4(p,j,pion,dep)==1){
                printf("Deplacement impossible, ceci n'est pas un saut\n");
            //printf(" %i \n %i \n",j[pion].pcase, p[j[pion].pcase].occupation); 
            }
            else{
                if(p[j[pion].pcase+2].occupation==0){
                    p[j[pion].pcase].occupation=0;
                    j[pion].pcase=j[pion].pcase-2;
                    p[j[pion].pcase].occupation=1;
                    return 1;
                }
                else{
                    printf("erreur, deplacement impossible\n");
                    return 0;
                }
            }
            break;
        case 3 ://deplacement haut gauche
            erreur=dephg4(p,j,pion,exesaut);
            if(erreur==0){
                erreur=depbd4(p,j,pion,exesaut);
                printf("Deplacement impossibe, ceci n'est pas un saut\n");
                return 0;
            }
            else{
                erreur=saut4(p,j,pion,dep);
                return 1;
            } 
            break;
        case 4 ://deplacement haut droite
            erreur=dephd4(p,j,pion,exesaut);
            if(erreur==0){
                erreur=depbg4(p,j,pion,exesaut);
                printf("Deplacement impossible, ceci n'est pas un saut\n");
                return 0;
            }
            else{
                erreur=saut4(p,j,pion,dep);
                return 1;
            }
            break;
        case 5 ://deplacement bas gauche
            erreur=depbg4(p,j,pion,exesaut);
            if(erreur==0){
                erreur=dephd4(p,j,pion,exesaut);
                printf("Deplacement impossible, ceci n'est pas un saut\n");
                return 0;
            }
            else{
                erreur=saut4(p,j,pion,dep);
                return 1;
            }
            break;
        case 6 ://deplacement bas droite
            erreur=depbd4(p,j,pion,exesaut);
            if(erreur==0){
                erreur=dephg(p,j,pion,exesaut);
                printf("Deplacement impossible, ceci n'est pas un saut\n");
                return 0;
            }
            else{
                erreur=saut4(p,j,pion,dep);
                return 1;
            }
            break;
        case 7 ://stop
            return 0;
        }
}
int saut4(cases4 p[122],pions4 j[41],int pion,int dep){
    int erreur;
    switch (dep)
    {
    case 1://saut vers la gauche
        //printf("case 1 \n");
        //printf("%i\n",p[j[pion].pcase-2].occupation);
        //printf("%i \n",j[pion].pcase);
        if(p[j[pion].pcase-2].occupation==0&&antisaut4(p,j,pion,dep)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase-2;
            p[j[pion].pcase].occupation=1;
            erreur=0;
            //affichage(p,j);
            //printf("saluuuuut\n");
        }
        else{
            erreur=1;
            printf("occupé\n");
        }
        return erreur;
        break;
    case 2://saut vers la droite
        if(p[j[pion].pcase+2].occupation==0&&antisaut4(p,j,pion,dep)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+2;
            p[j[pion].pcase].occupation=1;
            erreur=0;
        }
        else{
            printf("occupé\n");
            erreur=1;
        }
        return erreur;
        break;
    case 3://deplacement haut gauche
        erreur=sauthg4(p,j,pion);
        return erreur;
    break;
    case 4://deplacement haut droit
        erreur=sauthd4(p,j,pion);
        return erreur;
    break;
    case 5://deplacement bas gauche
        erreur=sautbg4(p,j,pion);
        return erreur;
    break;
    case 6 ://deplacement bas droite
        erreur=sautbd4(p,j,pion);
        return erreur;
    break;
    case 7://Passe le tour
        printf("tour termin%c \n",130);
        erreur=1;
    default:
        break;
    }
}

int deplacement4(cases4 p[122],pions4 j[41],int dep,int pion){
    int erreur=0;
    int ligne=0,nbsaut=0,exesaut=0,sot=0;
        printf("exesaut=%i\n",exesaut);
        switch (dep)
        {
        case 1://deplacement vers la gauche
            if(p[j[pion].pcase-1].occupation==0&&exesaut==0&&antisaut4(p,j,pion,dep)==1){
                p[j[pion].pcase].occupation=0;
                j[pion].pcase=j[pion].pcase-1;
                p[j[pion].pcase].occupation=1;
                erreur=0;
                //printf(" %i \n %i \n",j[pion].pcase, p[j[pion].pcase].occupation);
            }
            else{
                if(exesaut==1){
                    erreur=2;
                }
                else{
                    erreur=1;
                }
                //printf(" %i \n %i \n",j[pion].pcase, p[j[pion].pcase].occupation);
            }
            break;
        case 2 ://deplacement vers la droite
            if(p[j[pion].pcase+1].occupation==0&&exesaut==0&&antisaut4(p,j,pion,dep)==1){
            p[j[pion].pcase].occupation=0;
            j[pion].pcase=j[pion].pcase+1;
            p[j[pion].pcase].occupation=1;
            //printf(" %i \n %i \n",j[pion].pcase, p[j[pion].pcase].occupation); 
            }
        else{
            if(exesaut==1){
                    erreur=2;
                }
                else{
                    erreur=1;
                }
            }
            break;
        case 3 ://deplacement haut gauche
            erreur=dephg4(p,j,pion,exesaut);
            printf("erreur : %i\n",erreur);
            break;
        case 4 ://deplacement haut droite
        if(exesaut==0){
            erreur=dephd4(p,j,pion,exesaut);
            printf("erreur : %i\n",erreur);
        }
            break;
        case 5 ://deplacement bas gauche
        if(exesaut==0){
            erreur=depbg4(p,j,pion,exesaut);
            printf("erreur : %i\n",erreur);
        }
            break;
        case 6 ://deplacement bas droite
            erreur=depbd4(p,j,pion,exesaut);
            printf("erreur : %i\n",erreur);
            break;
        }
        if(erreur==1){
            erreur=saut4(p,j,pion,dep);
            exesaut=1;
            nbsaut+=1;
        }
        if(erreur==2){
            printf("Erreur, deplacement impossible\n");
            exesaut=0;
        }
        affichage4(p,j);
        if(exesaut==1){
            do{
                printf("Entrez le saut que vous souhaitez realiser\n entrez 7 pour arreter votre tour\n");
                scanf("%i",&dep);
                sot=enchainement4(p,j,pion,dep,exesaut);
                affichage4(p,j);
            }while(sot!=0);
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
void wesh4(int tour){
    if(tour==1) printf("Au tour de l'%cquipe bleu \n",130);
    if(tour==2) printf("Au tour de l'%cquipe rouge\n",130);
    if(tour==3) printf("Au tour de l'%cquipe blanc\n",130);
    if(tour==4) printf("Au tour de l'%cquipe cyan\n",130);
void Jeu4(){
    cases4 plateau[122];
    pions4 joueurs[41];
    reset4(joueurs);
    resetplateau4(plateau);
    int i;
    for(i=0;i<122;i++){
        plateau[i].aff='.';
    }
    saisiecases4(plateau,joueurs);
    saisiedefaut4(plateau,joueurs);
    int erreur;
    affichage4(plateau,joueurs);
    occupation4(plateau,joueurs);
    int run=1,tour=1,dep;
    char rep='0';
    while(run==1){
        wesh4(tour);
        //do{
            printf("Veuillez Entrer la case :\n");
            fflush(stdin);
            scanf("%c",&rep);
        //}while(rep!='1'||rep!='2'||rep!='3'||rep!='4'||rep!='5'||rep!='6'||rep!='7'||rep!='8'||rep!='9'||rep!='0');
        int temp=recherchepion4(joueurs,tour,rep);
        printf("Quel d%cplacement souhaitez vous faire ?\n",130);
        printf("Entrez 1 pour aller vers la gauche\nEntrez 2 pour aller vers la droite\nEntrez 3 pour monter %c gauche\nEntrez 4 pour monter %c droite\nEntrez 5 pour descendre %c gauche\nEntrez 6 pour descendre %c droite\n",133,133,133,133);
        do{
            scanf("%i",&dep);
            erreur=deplacement4(plateau,joueurs,dep,temp);
            //printf("dans boucle do while \n");
        }while(dep>7||erreur==1);
        affichage4(plateau,joueurs);
        /*test(plateau,joueurs);
        for(i=0;i<122;i++){
            printf("num case:%i  |occupation : %i\n",plateau[i].nbcase,plateau[i].occupation);
        
        affichage(plateau,joueurs);*/
        if(tour<6){
            tour+=1;
        }
        else{
            tour=1;
        }
    }
}
