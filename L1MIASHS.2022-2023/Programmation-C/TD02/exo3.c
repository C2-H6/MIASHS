#include <stdio.h>

int errorManagement(int h, int m, int s)
{
    if (h > 23 || m > 59 || s > 59) {
        (void)printf("erreur la date est invalide\n");
        return 1;
    }
    return 0;
}

int main() {
    int h, m, s;

    (void)scanf("%d %d %d", &h, &m, &s);
    if (errorManagement(h,m,s)) return 1;

    if (++s == 60) {
        s = 0;
        if (++m == 60) {
            m = 0;
            if (++h == 24)
                h = 0;
        }
    }
    (void)printf("il est %d:%d:%d\n", h, m, s);
    return 0;
}