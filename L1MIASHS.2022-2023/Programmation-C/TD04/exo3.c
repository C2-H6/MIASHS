#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Taille 5

int main(void)
{
    int tab[Taille - 1];
    srand(time(NULL)); //exercice .3
    int tmp, max = 0; //exercice .4
    int debut = 0; //exercice .6

    //exercice .2
    for (size_t i = 0; i < Taille; ++i)
        tab[i] = rand() % 25;
    
    //exercice .3
    for (size_t i = 0; i < Taille; ++i)
        (void)printf("%d\n", tab[i]);


    //exercice .4
    for (size_t i = 0; i < Taille; ++i)
        if (tab[max] < tab[i])
            max = i;
    (void)printf("la valeur max est %d\n", tab[max]);


    //exercice .5
    tmp = tab[debut];
    tab[debut] = tab[max];
    tab[max] = tmp;


    //exercice .6
    //for (int i = 0; i < Taille - 1; ++i) {
    //    max = -1;
     //   for (size_t i = debut; i < Taille; ++i)
      //      if (max == -1 || tab[max] < tab[i])
      //          max = i;
    //tmp = tab[debut];
    //tab[debut++] = tab[max];
    //tab[max] = tmp;
    //}

    //exercice .7
    for (size_t i = 0; i < Taille; ++i)
        (void)printf("%d\n", tab[i]);

    return 0;
}