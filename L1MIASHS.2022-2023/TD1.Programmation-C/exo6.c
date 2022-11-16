#include <stdio.h>

int entier(int nbr)
{
    return (nbr % 10) ? nbr : 0;
}

int main()
{
    int x, y, rep;

    printf("donnez  la taille en X et en Y\n");
    if (scanf("%d %d",&x, &y)) {
        x = x / 10;
        y = y / 10;
        (void)printf("il faut %d carrelages\n", x * y + entier(x) + entier(y) + (x && y));
    }
    return 0;
}
