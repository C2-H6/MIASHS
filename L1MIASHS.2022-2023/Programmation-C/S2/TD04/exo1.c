#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NDAY 366

float moyenne(char []);
int complet(char []);
float *moyenneSaisons(char [], int);
int strctPos(float *);

int main(void)
{
    printf("%.2f\n", moyenne("petrol"));
    printf("%d\n", complet("petrol"));
    float *tmp = moyenneSaisons("petrol", complet("petrol"));

    for (int i = 0; i < 4; ++i)
        printf("%.2f\n", tmp[i]);
    printf("%d\n", strctPos(moyenneSaisons("petrol", complet("petrol"))));

    return 0;
}

//---------------------------- file interaction ----------------------------//


FILE *openFile(char *fName, char *mode)
{
    FILE *file = fopen(fName, mode);

    if (!file) {
        printf("Error opening file %s\n", fName);
        exit(1);
    }
    return file;
}



//---------------------------- Function ex01 ----------------------------//


float moyenne(char nomf[]) 
{
    FILE *file = openFile(nomf, "r");
    float moyenne = 0, somme = 0;

    while(fscanf(file, "%f", &moyenne) == 1)
        somme += moyenne;
    
    fclose(file);
    return somme / NDAY;
}

int complet(char nomf[]) //j'aime pas car var tmp
{
    FILE *file = openFile(nomf, "r");
    int nbrLines = 1;
    int c;

    while ((c = getc(file)) != EOF)
        if (c == '\n')
            ++nbrLines;

    fclose(file);
    return nbrLines;
}

float *moyenneSaisons(char nomf[], int nbrLines)
{
    FILE *file = openFile(nomf, "r");
    static float saisons[4] = {0, 0, 0, 0};
    float tmp;

    for(int i = 0; i < nbrLines; ++i) {
        fscanf(file, "%f", &tmp);
        saisons[i % (nbrLines / 4)] += tmp;
    }

    for (int i = 0; i < 4 ; ++i)
        saisons[i] / (nbrLines / 4);

    fclose(file);
    return saisons;
}

int strctPos(float *tab)
{
    if (tab[0] > tab[1])
        return 1;
    else if (tab[1] > tab[2])
        return 2;
    else if (tab[2] > tab[3])
        return 3;
    return -1;
}