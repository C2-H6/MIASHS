#include <stdio.h>
#define Size 3

int main(void)
{
    double tab[Size];
    double value = 0; //exercice .3
    double found; //exercice .4
    int nbr = 0; //exercice .5 

    //exercice .1
    for(size_t i = 0; i < Size; ++i)
        (void)scanf("%lf", &tab[i]);

    //exercice .2
    (void)printf("le contenue du tableau est : \n");
    for(size_t i = 0; i < Size; ++i)
        (void)printf("%lf | ", tab[i]);
    (void)printf("\n");

    //exercice .3
    for(size_t i = 0; i < Size; ++i)
        value += tab[i];
    (void)printf("la somme du tableau est : \n%lf\n", value);

    //exercice .4
    (void)printf("un nombre que vous chercher dans le tableau : \n");
    (void)scanf("%lf", &found);
    for (size_t i = 0; i < Size; ++i) {
        if (tab[i] == found) {
            printf("Le nombre %lf existe au %zu emplacement\n", found, i + 1);
            break;
        }
    }

    //exercice .5
    (void)printf("combien de fois un nombre que vous chercher est dans le tableau : \n");
    (void)scanf("%lf", &found);
    for (size_t i = 0; i < Size; ++i)
        if (tab[i] == found)
            ++nbr;
    (void)printf("la valeur %lf est presente : %d fois dans le tableau\n", found, nbr);

    return 0;
}