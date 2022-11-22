#include <stdio.h>

int main()
{
    int a,b;

    (void)scanf("%d %d", &a,&b);

    if (a == b)
        (void)printf("egauts\n");
    a > b ? (void)printf("a : %d supperieur\n", a) : (void)printf("b  : %d superieur\n", b);
    return 0;
}