#include <stdio.h>

int main() 
{
    int mnth, yrs;
    int lMnth[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    (void)scanf("%d %d", &yrs, &mnth);

    if (mnth < 1 && mnth > 12) {
        (void)printf("error\n");
        return 1;
    }
    if (!(yrs % 4) && ((yrs  % 100) && (yrs % 4000)))
        mnth = 0;

    (void)printf("%d jours \n", lMnth[mnth]);
    return 0;
}


