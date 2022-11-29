#include <stdio.h>

int main()
{
    int n, nbr, tmp = 0;

    (void)printf("donner le nombre d'operation\n");
    (void)scanf("%d", &n);

    for (int i = 1  ; i <= n; ++i) {
        (void)scanf("%d", &nbr);
        tmp += nbr;
    }

    (void)printf("%d\n",tmp / n);
    return 0;
}