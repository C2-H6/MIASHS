#include <stdio.h>

int error(int nbr)
{
    if (nbr < 0)
        return 1;
    return 0;
}

int main()
{
    int nbr, f = 1;

    (void)scanf("%d", &nbr);
    if (error(nbr)) return 1;

    for (int i = 1; i <= nbr; ++i)
        f *= i;

    (void)printf("la factorielle de %d est %d\n", nbr, f);
    return 0;
}
