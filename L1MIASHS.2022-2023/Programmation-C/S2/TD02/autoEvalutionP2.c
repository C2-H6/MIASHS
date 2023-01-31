#include <stdio.h>

void calculeTTC(float *, float);
void soldes(int, float *);

enum tax {T0 = 200, T1 = 150, T2 = 200};


int main(void)
{
    float tab0[] = {100, 150, 200, 0};
    float tab1[] = {100, 150, 200, 0};
    float tab2[] = {100, 150, 200, 0};

    soldes(20, tab0);
    
    for (int i = 0; tab0[i]; ++i)
        printf("%f\n", tab0[i]);    
    calculeTTC(&tab0[0], T0 / 10);

    printf("%f\n", tab0[0]);

    return 0;
}

void soldes(int reduction, float *tab)
{
    for (int i = 0; tab[i]; ++i)
        tab[i] -= ((tab[i] / 100) * reduction);
}

void calculeTTC(float *price, float tax)
{
    *price += ((*price / 100) * tax);
}
