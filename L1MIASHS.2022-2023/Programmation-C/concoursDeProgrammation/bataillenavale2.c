#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define T 6

typedef char grille[T][T];

    grille bateau_player;
    grille tire_player;
    grille bateau_ordi;
    grille tire_ordi;


    int nbrBateaux = 0;
    int nbrBateauxStart = 0;

void init_grille(grille);
void affiche(grille);

void placer_bateau1(grille t);
void placer_bateau1_ordi(grille, int *);

char ouvrirLeFeux(grille, int , int);
void tirer_ordi(grille);
void tirer(grille, int *);

int verif_fin_partie(grille);


int main()
{
    srand(time(NULL));

    init_grille(bateau_player);
    init_grille(tire_player);
    init_grille(bateau_ordi);
    init_grille(tire_ordi);


    affiche(bateau_player);
    placer_bateau1(bateau_player);
    affiche(bateau_player);


    placer_bateau1_ordi(bateau_ordi, &nbrBateaux);
    ++nbrBateauxStart;

    affiche(bateau_ordi);

    tirer(tire_player, &nbrBateaux);
    affiche(tire_player);

    tirer_ordi(tire_ordi);
    affiche(tire_ordi);

    if (verif_fin_partie(tire_ordi))
        printf("fin de partie\n");
    return 0;
}

/*-------------------------- Etape 6 : tire joueur---------------------------*/

int verif_fin_partie(grille t)
{
    int nbt = 0;

    for(int i = 0; i < T; ++i)
        for(int j=0; j < T; ++j)
            if(t[i][j]=='t')
                ++nbt;
    
    return (nbt == nbrBateauxStart);
}

/*-------------------------- Etape 5 : tire joueur---------------------------*/


void tirer(grille t, int *pos)
{
    int x,y;

    do {
        printf("Donnez les cordonnees X et Y pour tirer\n");
        scanf("%d %d",&x, &y);
    } while (!(t[x][y] == '.'));

    t[x][y] = ouvrirLeFeux(bateau_ordi, x, y);
    if (t[x][y] == 't')
        --(pos);
}

/*-------------------------- Etape 4 : Ordinateur tire ---------------------------*/

char ouvrirLeFeux(grille t,int x,int y)
{
    if (t[x][y] == '.')
        return('r');
    return('t');
}

void tirer_ordi(grille t){

    int x = 0;
    int y = 0;
    
    do{
        x = rand() % (T - 1);
        y = rand() % (T - 1);
    } while(!(t[x][y] == '.'));

    t[x][y] = ouvrirLeFeux(bateau_player, x, y);

}

/*-------------------------- Etape 3 : Ordinateur ajoute bateau taille 1 ---------------------------*/

int empty_ordi(grille t, int x, int y)
{
    if (x < T && y < T)
        if (t[x][y] == '.')
            return 1;

    return 0;
}

void placer_bateau1_ordi(grille t, int *pos)
{
    int nbr1 = 0;
    int nbr2 = 0;

    do {
        nbr1 = rand() % (T - 1);
        nbr2 = rand() % (T - 1);
    } while (!empty_ordi(t, nbr1, nbr2));
    
    ++(*pos);
    t[nbr1][nbr2] = '1';
}

/*-------------------------- Etape 2 : Ajouter bateau taille 1 ---------------------------*/


int empty(grille t, int x, int y)
{
    if (x < T && y < T){
        if (t[x][y] == '.') {
            printf("Coordonnee confirme.\n");
            return 1;
        } else
            printf("Emplacement deja complet.\n");
    } else
        printf("Coordonnee invalide\n");

    return 0;
}

void placer_bateau1(grille t)
{
    int x,y;

    do {
        printf("Donnez les cordonnees X et Y d'un bateau\n");
        scanf("%d %d",&x, &y);
    } while (!empty(t, x, y));

    t[x][y] = '1';
}
void placer_bateau2(grille t){
    int x,y,sens;
    do {
        printf("Quel orientation? 0vers la droite, 1 vers le bas.");
        scanf("%d",&sens);
        printf("Donnez les cordonnees X et Y de la tête du bateau\n");
        scanf("%d %d",&x, &y);
    } while (!empty(t, x, y)&&!empty(t,x+sens,y+1-sens));

    t[x][y]='2';
    t[x+sens][y+1-sens]='2';
    nbrBateauxStart+=2;

}
void placer_bateau3(grille t){
    int x,y,sens;
    do {
        printf("Quel orientation? 0vers la droite, 1 vers le bas.");
        scanf("%d",&sens);
        printf("Donnez les cordonnees X et Y de la tête du bateau\n");
        scanf("%d %d",&x, &y);
    } while (!empty(t, x, y)&&!empty(t,x+sens,y+1-sens)&&!empty(t,x+2*sens,y+2*(1-sens)));

    t[x][y]='3';
    t[x+sens][y+1-sens]='3';
    t[x+2*sens][y+2*(1-sens)]='3';
    nbrBateauxStart+=3;
}
void placer_bateau2_ordi(grille t, int *nbrBateauxStart){
    int nbr1 = 0;
    int nbr2 = 0;
    int sens=0;

    do {
        sens=rand()%2;
        nbr1 = rand() % T;
        nbr2 = rand() % T;
    } while (!empty_ordi(t, nbr1, nbr2)&&!empty(t,nbr1+sens,nbr2+1-sens));
    
    (*pos)+=2;
    t[nbr1][nbr2] = '2';
    t[nbr1+sens][nbr2+1-sens] = '2';
}
void placer_bateau2_ordi(grille t, int *nbrBateauxStart){
    int nbr1 = 0;
    int nbr2 = 0;
    int sens=0;
    do {
        sens=rand()%2;
        nbr1 = rand() % T;
        nbr2 = rand() % T;
    } while (!empty_ordi(t, nbr1, nbr2)&&!empty(t,nbr1+sens,nbr2+1-sens)&&!empty(t,nbr1+2*sens,nbr2+2*(1-sens)));
    
    (*pos)+=3;
    t[nbr1][nbr2] = '3';
    t[nbr1+sens][nbr2+1-sens] = '3';
    t[nbr1+2*sens][nbr2+2*(1-sens)] = '3';
}



/*-------------------------- Etape 1 : initialisation de grille ---------------------------*/

void init_grille(grille t)
{
    for(int i = 0; i < T; ++i)
        for(int j=0; j < T; ++j)
            t[i][j]='.';
}

/*-------------------------- Etape 1 : Affichage ---------------------------*/

void affiche(grille t)
{
    printf("\n");
    for(int i = 0; i < T; ++i) {
        for(int j = 0; j < T; ++j) {
            if(j == 0) {
                printf("%d | %c", i, t[i][j]);
            } else if (j == T -1) {
                printf("| %c |\n", t[i][j]);
            } else printf("| %c", t[i][j]);
        }
    }
}