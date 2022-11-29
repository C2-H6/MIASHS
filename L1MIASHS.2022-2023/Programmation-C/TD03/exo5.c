#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int secret(void)
{
    srand(time(NULL));
    return rand() % 50;
}

void try(int nbrTry)
{
        if (nbrTry == 1)
        printf("Vous avez trouver du prenier coup !!! \n");
    if (nbrTry <= 5)
        printf("Vous avez trouver en mois de 5 essaies\n");
    if (nbrTry > 5)
        printf("pVous avez trouver en plus de 5 essaies\n");
}

int main()
{
    int scrt = secret();
    int nbr, nbrTry = 0;

    while (1) {
        (void)scanf("%d", &nbr);
        if (nbr < 0 || nbr > 49)
            continue;
        ++nbrTry;
        if (nbr < scrt)
            printf("la valeur est trop petite\n");
        else if ( nbr > scrt)
            printf("la valeur est trop grande\n");
        else
            break;
    }

    printf("Vous avez trouver le bon nombre !!!\n");
    try(nbrTry);

    return 0;
}