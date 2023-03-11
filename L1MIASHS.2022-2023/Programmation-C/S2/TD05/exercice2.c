//de Maeyer Ethan

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void fillTab(int []);
int *minMaxMoy(int []);

#define MOIS 2//comme nous somme en mai alors 5 mois sont ecouler

int tabSize = MOIS;


int main(void)
{
    int price[MOIS];

    fillTab(price);
    for (int i = 0; i < MOIS; ++i)
        printf("%d\n", price[i]);

    int *nbr = minMaxMoy(price);

    printf("%d\n", nbr[0]);
    printf("%d\n", nbr[1]);
    printf("%d\n", nbr[2]);

//    int *nT = newTab(tab[], 2);

    return 0;
}

/*---------------------------------- part c ----------------------------------------*/

int *newTab(int tab[])
{
    //tabSize++;

}

/*---------------------------------- part b ----------------------------------------*/

int *minMaxMoy(int price[])
{
    static int tab[3];

    tab[0] = INT_MAX;
    tab[1] = INT_MIN;
    tab[2] = 0;

    for (int i = 0; i < MOIS; ++i) {
        if (price[i] < tab[0])
            tab[0] = price[i];
        if (price[i] > tab[1])
            tab[1] = price[i];
        tab[2] += price[i];
    }
    tab[2] /= MOIS;

    return tab;
}

/*---------------------------------- part a ----------------------------------------*/


void fillTab(int price[])
{
    int tmp;

    for (int i = 0; i < MOIS; ++i) {
        printf("donnez un prix\n");
        scanf(" %d", &tmp);
        price[i] = tmp;
    }
}


