#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int *fileToTab(char *, int);
void chargecours(char [], float []);
void chargemois(char [], float []);
int giveMounth(int, float []);
int *giveDay(int, float []);
float MoyenneMoneyMounthly(float *, float *, int);
int strctlBggr(float *, float *);

FILE *open(char *, char *);

int main(void)
{
    float tcours[366];
    float tmois[12];


    chargecours("petrol", tcours);
    chargemois("jours", tmois);

    printf("%d\n", giveMounth(2, tmois));


    int *frstLst = giveDay(3, tmois);
    printf("debut et fin : %d %d\n", frstLst[0], frstLst[1]);

    printf("moyenne %.2f\n", MoyenneMoneyMounthly(tcours, tmois, 3));

    if (strctlBggr(tcours, tmois))
        printf("tout les mois ne sont pas croissant\n");
    else
        printf("les mois sont croissant\n");
    return 0;
}


//---------------------------- exo2 ----------------------------//


int strctlBggr(float *tcours, float *tmois)
{
    float prev = MoyenneMoneyMounthly(tcours, tmois, 1);
    float new = -1;

    for (int i = 1; i <= 12; ++i)
        if ((prev = new) < (new = MoyenneMoneyMounthly(tcours, tmois, i)))
            return -1;

    return new;
}


float MoyenneMoneyMounthly(float *tcours, float *tmois, int mounth)
{
    int *listDay  = giveDay(mounth, tmois);
    float nbr = 0;

    for (int i = listDay[0]; i <= listDay[1]; ++i)
        nbr += tmois[i - 1];

    return nbr;
}

int *giveDay(int mounth, float tab[])
{
    static int frstLst[2] = {1, 0};

    frstLst[0] = 1;
    for(int i = 1; i < mounth; ++i)
        frstLst[0] += giveMounth(i, tab);
    frstLst[1] = frstLst[0] + giveMounth(mounth, tab) - 1;
    return frstLst;
}

int giveMounth(int mounth, float tab[])
{
    return (int)tab[mounth - 1];
}

void chargecours(char nomf[], float tab[]) 
{
    FILE *file = open(nomf, "r"); 
    char buff[255];

    for (int i = 0; fgets(buff, 255, file); ++i)
            tab[i] = atof(buff);
    fclose(file);
}

void chargemois(char nomf[], float tab[]) 
{
    FILE *file = open(nomf, "r"); 
    char buff[255];

    for (int i = 0; fgets(buff, 255, file); ++i)
            tab[i] = atof(buff);
    fclose(file);
}


//---------------------------- interaction fichier ----------------------------//


FILE *open(char *fName, char *mode)
{
    FILE *file = fopen(fName, mode);

    if (!file) {
        printf("Unable to open file %s\n", fName);
        exit(1);
    }
    return file;
}
