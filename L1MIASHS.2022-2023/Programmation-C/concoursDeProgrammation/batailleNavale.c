#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define T 6

typedef char grille[T][T];

/*-------- Variables globales --------*/

    grille bateau_player;
    grille tire_player;
    grille bateau_ordi;
    grille tire_ordi;
    int nbrBateaux = 0;
    int nbrBateauxStart = 0;

/*------------------------------------*/

void init_grille(grille);
void affiche(grille);

void placer_bateau1(grille t);
void placer_bateau1_ordi(grille, int *);
int empty(grille, int, int);

char ouvrirLeFeux(grille, int , int);
void tirer_ordi(grille);
void tirer(grille, grille, int *);

int verif_fin_partie(grille);

void initializeGame();
void placerBateau();


int main()
{
    initializeGame();
    placerBateau();

    while (1) {
        (void)printf("--- le tableau du joueur ---\n");
        affiche(bateau_player);
        (void)printf("--- le tableau de tire du joueur ---\n");
        affiche(tire_player);


        //compiler avec debug pour afficher le tableau de bateau de l'ia
        #if DEBUG
        (void)printf("--- le tableau de tire de l'ia ---\n");
        affiche(bateau_ordi);
        #endif
        

        tirer(tire_player, bateau_ordi, &nbrBateaux);
        tirer_ordi(tire_ordi);

        if (verif_fin_partie(tire_ordi)) {
            (void)printf("Vous avez perdu !!!\n");
            break;
        }
        if (verif_fin_partie(tire_player)) {
            (void)printf("Vous avez gagner !!!\n");
            break;
        }
    }


    return 0;
}
/*-------------------------- Etape 8 : Bonus ---------------------------*/

/*void placer_bateau2(grille t)
{
    int x,y,sens;

    do {
        (void)printf("Quel orientation? 0vers la droite, 1 vers le bas.\n");
        (void)scanf("%d",&sens);
        (void)printf("Donnez les cordonnees X et Y de la tête du bateau\n");
        (void)scanf("%d %d",&x, &y);
    } while (!empty(t, x, y) && !empty(t, x + sens, y + 1 - sens)&&x+sens<T&&y+1-sens<T);

    t[x][y] = '2';
    t[x + sens][y + 1 - sens] = '2';
    nbrBateauxStart += 2;

}

void placer_bateau3(grille t){
    int x,y,sens;
    do {
        printf("Quel orientation? 0vers la droite, 1 vers le bas.");
        scanf("%d",&sens);
        printf("Donnez les cordonnees X et Y de la tête du bateau\n");
        scanf("%d %d",&x, &y);
    } while (!empty(t, x, y)&&!empty(t,x+sens,y+1-sens)&&!empty(t,x+2*sens,y+2*(1-x)));

    t[x][y]='3';
    t[x+sens][y+1-sens]='3';
    t[x+2*sens][y+2*(1-sens)]='3';
    nbrBateauxStart+=3;

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
}*/

/*-------------------------- Etape 7 : deroulement de la partie ---------------------------*/

void placerBateau()
{
    placer_bateau1(bateau_player);

    placer_bateau1_ordi(bateau_ordi, &nbrBateaux);
}

void initializeGame()
{
    srand(time(NULL));

    init_grille(bateau_player);
    init_grille(tire_player);
    init_grille(bateau_ordi);
    init_grille(tire_ordi);
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


void tirer(grille t, grille tt, int *pos)
{
    int x,y;

    do {
        (void)printf("Donnez les cordonnees X et Y pour tirer\n");
        (void)scanf("%d %d",&x, &y);
    } while (!(t[x][y] == '.'));

    t[x][y] = ouvrirLeFeux(tt, x, y);
    if (t[x][y] == 't')
        --(pos);// calculer mais pas utiliser
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
        x = rand() % T;
        y = rand() % T;
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
        nbr1 = rand() % T;
        nbr2 = rand() % T;
    } while (!empty_ordi(t, nbr1, nbr2));
    
    ++(*pos);
    t[nbr1][nbr2] = '1';
}

/*-------------------------- Etape 2 : Ajouter bateau taille 1 ---------------------------*/


int empty(grille t, int x, int y)
{
    if (x < T && y < T){
        if (t[x][y] == '.') {
            (void)printf("Coordonnee confirme.\n");
            return 1;
        } else
            (void)printf("Emplacement deja complet.\n");
    } else
        (void)printf("Coordonnee invalide\n");

    return 0;
}

void placer_bateau1(grille t)
{
    int x,y;

    do {
        (void)printf("Donnez les cordonnees X et Y d'un bateau\n");
        (void)scanf("%d %d",&x, &y);
    } while (!empty(t, x, y));

    t[x][y] = '1';
    ++nbrBateauxStart;
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
    (void)printf("\n");
    for(int i = 0; i < T; ++i) {
        for(int j = 0; j < T; ++j) {
            if(j == 0) {
                (void)printf("%d | %c", i, t[i][j]);
            } else if (j == T -1) {
                (void)printf("| %c |\n", t[i][j]);
            } else (void)printf("| %c", t[i][j]);
        }
    }
}