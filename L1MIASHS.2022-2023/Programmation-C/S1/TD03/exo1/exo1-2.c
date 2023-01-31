#include <stdio.h>

int main()
{
    for (char i = 1; i <= 100; ++i)
        (void)printf("%4.0d", i);
    return 0;
}