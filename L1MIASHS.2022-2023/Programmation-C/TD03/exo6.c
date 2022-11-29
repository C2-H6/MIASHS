#include <stdio.h>

int error(int x, int y)
{
    if (!x || !y)
        return 1;
    return 0;
}

int main()
{
    int x,y;

    printf("donnez la longueur : x et la hauteur : y\n");
    (void)scanf("%d %d", &x, &y);
    if (error(x, y)) return 1;

    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j)
            printf("#");
        printf("\n");
    }
    return 0;
}