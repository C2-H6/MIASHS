#include <stdio.h>

int main()
{
    (void)printf("nombre divisible par 7 OU 13\n");
    for (char i = 1; i <= 100; ++i)
        if (!(i % 7 || !(i % 13)))
            (void)printf("%d\n", i);
    
    (void)printf("nombre divisible par 7 ET 13\n");
    for (char i = 1; i <= 100; ++i)
        if (!(i % 7) && !(i % 13))
            (void)printf("%d\n", i);
    
    return 0;
}