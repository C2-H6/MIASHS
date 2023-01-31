#include <stdio.h>

int factorielle(int);
int calculX(int, int);
int calculY(int, int);
void pmu(int, int);

int main(void)
{
    pmu(4, 2);
    return (0);
}

void pmu(int n, int p)
{
    printf("Dans le désordre, il y a 1 chance de gagner sur %d\n", calculX(n,p));
    printf("Dans l'ordre, il y a 1 chance de gagner sur %d\n", calculY(n,p));   
}

int calculX(int n, int p)
{
    return(factorielle(n) / ( factorielle(p) * factorielle (n - p)));
}

int calculY(int n, int p)
{
    return(factorielle(n) / factorielle (n - p));
}

int factorielle(int n)
{
    int fact = 1;

    for (int i = 1; i <= n; ++i)
        fact *= i;
    return (fact);
}



