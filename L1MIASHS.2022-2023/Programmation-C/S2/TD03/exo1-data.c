#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


#define FNAME "tmprt"
#define BUFSIZE 255

int tmprtMoyenne(char *);
int tmprtMax(char *);
int tmprtMin(char *);
int tmprtMinMax(char *);
int tmprtPlusMoyenne(char *);
int tmprtPlusValue(char *, int);
int saison(char *);
int incrmt(char *);


int main(void) 
{
    printf("Temperature moyenne : %d\n", tmprtMoyenne(FNAME));
    printf("Mois avec la temperature max : %d\n", tmprtMax(FNAME));
    printf("Mois avec la temperature min : %d\n", tmprtMin(FNAME));
    if (tmprtMinMax(FNAME))
        printf("oui\n");
    else 
        printf("non\n");
    printf("Nombre de mois au dessus de la temperature moyenne: %d\n", tmprtPlusMoyenne(FNAME));
    printf("Nombre de mois au dessus de la temperature donner: %d\n", tmprtPlusValue(FNAME, 13));
    if (saison(FNAME))
        printf("Il fait froid en hiver et chaud en ete\n");
    else 
        printf("Ya plus de saisons !!!\n");
    if (incrmt(FNAME))
        printf("Chaque mois un peu plus\n");
    else 
        printf("Tout ca n'a aucun sens !!!\n");
    return 0;
}

FILE *open(char *fName)
{
    FILE *file = fopen(fName, "r");

    if (!file) {
        printf("Unable to open file %s\n", FNAME);
        exit(1);
    }
    return file;
}

int tmprtMoyenne(char *fName)
{
    FILE *file = open(fName);
    char buff[BUFSIZE];

    int nbr = 0;

    while (fgets(buff, BUFSIZE, file))
        nbr += atoi(buff);

    fclose(file);
    return nbr / 12;
}

int tmprtMax(char *fName)
{
    FILE *file = open(fName);
    char buff[BUFSIZE];
    int nbr = 0;
    int mounth = 0;

    for (int i = 0; fgets(buff, BUFSIZE, file) != NULL; ++i) {
        if (nbr < atoi(buff)) {
            nbr = atoi(buff);
            mounth = i;
        }
    }

    fclose(file);
    return mounth + 1;
}

int tmprtMin(char *fName)
{
    FILE *file = open(fName);
    char buff[BUFSIZE];
    int nbr = INT_MAX;
    int mounth = 0;

    for (int i = 0; fgets(buff, BUFSIZE, file) != NULL; ++i) {
        if (nbr > atoi(buff)) {
            nbr = atoi(buff);
            mounth = i; 
        }
    }

    fclose(file);
    return mounth + 1;
}

int tmprtMinMax(char *fName)
{
    int min = tmprtMin(FNAME);
    int max = tmprtMax(FNAME);

    if ((max + 1 == min) || max - 1 == min)
        return 1;
    return 0;
}

int tmprtPlusMoyenne(char *fName)
{
    int tM = tmprtMoyenne(FNAME);

    FILE *file = open(fName);
    char buff[BUFSIZE];
    int moreValue = 0;

    for (int i = 0; fgets(buff, BUFSIZE, file) != NULL; ++i)
        if (tM < atoi(buff))
            ++moreValue;

    fclose(file);
    return moreValue;
}


int tmprtPlusValue(char *fName, int nbr)
{
    FILE *file = open(fName);
    char buff[BUFSIZE];
    int moreValue = 0;

    for (int i = 0; fgets(buff, BUFSIZE, file) != NULL; ++i)
        if (nbr < atoi(buff))
            ++moreValue;

    fclose(file);
    return moreValue;
}

int saison(char *fName)
{
    FILE *file = open(fName);
    char buff[BUFSIZE];
    int saisons[] = {0, 0, 0 , 0};

    for(int i = 0; saisons[i]; ++i)
        for (int  j = 0; j <= 3 && fgets(buff, BUFSIZE, file) != NULL; ++j)
            saisons[i] == atoi(buff);

    if (saisons[0] < saisons[1] && saisons[1] < saisons[2] && saisons[2] < saisons[3])
        return 1;
    return 0;
}

int incrmt(char *fName)
{
    FILE *file = open(fName);
    char buff[BUFSIZE];
    int lstMounth = INT_MIN;

    for (int  i = 0; fgets(buff, BUFSIZE, file) != NULL; ++i)
        if (i <= 6)
            if (lstMounth > atoi(buff))
                return 0;
        else
            if (lstMounth < atoi(buff))
                return 0;
    return 1;
}