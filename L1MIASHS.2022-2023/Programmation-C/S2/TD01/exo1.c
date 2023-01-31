#include <stdio.h>

int puissancePos(int, int);
int puissance(int, int);

int main(void)
{
    printf("%d\n", puissance(4, 2));
    return 0;
}

int puissance(int x, int n)
{
    if (n >= 0)
        return puissancePos(x, n);
    return 1 / puissancePos(x, n * -1);
}

int puissancePos(int x, int n)
{
    int puis = 1;

    for (int i = 0; i < n; ++i)
        puis *= x;

    return puis;
}



