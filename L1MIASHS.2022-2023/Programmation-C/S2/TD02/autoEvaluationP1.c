#include <stdio.h>
#define SIZE 8


void aculestatistiques(int []);
int moyenne(int []);
int min(int []);
int max(int []);
int mediane(int []);
//int mode(int []);


int main(void)
{
    int t[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};//part du principe que bien placer

    aculestatistiques(t);
    return 0;
}


void aculestatistiques(int t[])
{
    printf("moyenne : %d\n", moyenne(t));
    printf("min : %d\n", min(t));
    printf("max : %d\n", max(t));
    printf("mediane : %d\n", mediane(t));
    //printf("mode : %d\n", mode(t));
    
}

int moyenne(int t[])
{
    int nbr = 0;

    for(int i = 0; i <= SIZE; ++i)
        nbr += t[i];
    
    return nbr / SIZE;
}

int min(int t[])
{
    int min = t[0];

    for(int i = 1; i <= SIZE; ++i)
        if (min > t[i])
            min = t[i];

    return min;
}

int max(int t[])
{
    int max = t[0];

    for(int i = 1; i <= SIZE; ++i)
        if (max < t[i])
            max = t[i];

    return max;
}

int mediane(int t[])
{
        return t[SIZE / 2];
}

/*int mode(int t[])
{
    int Max = 0;
    int itMax = 0;

    int tmpMax = 0;
    int tmpItmax = 0;

    for (int i = 1; i < SIZE, ++i)
        for (int j = i; )

        //
        return 0;

}*/