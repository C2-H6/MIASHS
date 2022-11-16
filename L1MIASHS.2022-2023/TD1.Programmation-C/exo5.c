#include <stdio.h>
#include <stdlib.h>

#define CR5 10

int onlyNbr(char *nbr)
{
    for (int i = 0; nbr[i]; ++i)
        if (nbr[i] < '0' || nbr[i] > '9') return 0;
    return 1;
}

void game(int nbr)
{
    if (nbr && nbr / 10) {
        (void)printf("il y a %d billets de 10\n", nbr / 10);
        nbr = nbr % 10;
    }
    if (nbr && nbr / 5) { 
        (void)printf("il y a %d billets de 5\n", nbr / 5);
        nbr = nbr % 5;
    }
    if (nbr && nbr / 2) { 
        (void)printf("il y a %d pièces de 2\n", nbr / 2);
        nbr = nbr % 2;
    }
    if (nbr && nbr / 1) { 
        (void)printf("il y a %d pièces de 1\n", nbr / 1);
        nbr = nbr % 1;
    }
}

int main(int ac, char **av)
{
    int nbr;

    if (ac == 2 && onlyNbr(av[1])) {
        game(atoi(av[1]));
        return 0;
    }
    if (ac != 2) {
        printf("donnez un nombre\n");
        if (scanf("%d", &nbr))
            game(nbr);
        return 0;
    }
    return 1;
}