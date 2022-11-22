#include <stdio.h>

int bssxtl(int mnth, int yrs)
{
    if (mnth == 2 && !(yrs % 4) && ((yrs  % 100) && (yrs % 4000)))
        return 0;
    return mnth;
}

int errorManagement(int m)
{
    if (m < 1 && m > 12) {
        (void)printf("error\n");
        return 1;
    }
    return 0;
}

int main()
{
    int y, m ,d; 
    int lMnth[13] = {29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    (void)scanf("%d %d %d", &y, &m, &d);
    if (errorManagement(m)) return 1;

    if (++d > lMnth[bssxtl(m, y)]) {
        d = 1;
        if (++m > 12) {
            m = 1;
            ++y;
        }
    }
    printf("%d:%d:%d\n", y, m ,d);
    return 0;
}