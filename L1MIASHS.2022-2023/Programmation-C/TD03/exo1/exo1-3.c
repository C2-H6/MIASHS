#include <stdio.h>

int main()
{
    for (int i = 1; i <= 100; ++i) {
        (void)printf("%4.0d", i);
        if (!(i % 10))
            (void)printf("\n");
    }
    return 0;
}