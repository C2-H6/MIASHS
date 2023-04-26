#include <stdio.h>

#define N 256
#define MAGASIN 50
#define VRAIE 1
#define FAUX 0

typedef struct {
    int jour;
    int mCarre;
    int mFrigo;
    int collecteur;
} boutique_t;

void metreLineaire(boutique_t *, int );
boutique_t createBoutique(int, int, int, int);
void printBoutique(boutique_t);
void allBoutique(boutique_t [MAGASIN], int);
void printAllDay(boutique_t [MAGASIN], int);

int main(void)
{
    boutique_t boutique = createBoutique(7, 157, 12, VRAIE);

    metreLineaire(&boutique, 156);
    printBoutique(boutique);


    boutique_t mBoutique[MAGASIN];
    allBoutique(mBoutique, MAGASIN); 
    printAllDay(mBoutique, MAGASIN);
    return 0;
}

/*---------------------------------------- 7 ----------------------------------------*/

void printAllDay(boutique_t boutique[MAGASIN], int nbr)
{
    for(int i = 0; i < nbr; ++i)
        printf("magasin %d : %d ouvert\n", i - 1, boutique[i].jour);
}
/*---------------------------------------- 6 ----------------------------------------*/


void allBoutique(boutique_t boutique[MAGASIN], int nbr)
{
    for(int i = 0; i < nbr; ++i)
        boutique[i] = createBoutique(7, 157, 12, VRAIE);
}

/*---------------------------------------- 4 ----------------------------------------*/

void printBoutique(boutique_t boutique)
{
    printf("jours ouvert : %d\nombre de metre carre : %d\n", boutique.jour, boutique.mCarre);
    printf("metre lineaire frigo : %d\npresence de collecteur %s\n", boutique.mFrigo, boutique.collecteur == 1 ? "oui" : "non");
}

/*---------------------------------------- 3 ----------------------------------------*/

void metreLineaire(boutique_t *boutique, int nValue)
{
    boutique->mFrigo = nValue;
}

/*---------------------------------------- 2 ----------------------------------------*/

boutique_t createBoutique(int a, int b, int c, int d)
{
    return ((boutique_t){a, b, c, d});
}