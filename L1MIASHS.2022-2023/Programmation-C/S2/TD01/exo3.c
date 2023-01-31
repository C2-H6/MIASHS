
#include <stdio.h>

#define N 2
int somme(int [], int);
int minim(int [], int);
void saisie(int [], int);

int main(void)
{
    int t[N + 1];

    saisie(t, N);
    printf("le tableau :");
    for (int i = 0; i <= N; ++i)
        printf("%d", t[i]);
    printf("\n");

    printf(" le nombre minimum : %d\n", minim(t, N));

    printf(" la somme du tableau : %d\n", somme(t, N));

    return 0;
}

void saisie(int t[], int size)
{
    int tmp = 0;

    for (int i = 0; i <= size; ++i) {
        printf("donnez la valeur du %d element du tab\n", i);   
        scanf("%d", &t[i]);
    }

}

int somme(int tab[], int size)
{
    int som = 0;

    for(int i = 0; i <= size; ++i)
        som += tab[i];
    return som;
}

int minim(int t[], int size)
{
    int min = 0;

    for(int i = 1; i <= size; ++i)
        if (t[i] < t[min])
            min = i;
    return t[min];
}


