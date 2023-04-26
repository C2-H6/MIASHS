#include <stdlib.h>
#include <stdio.h>

#define MONTH 12
#define MAX 50

int nbrClient = 0;

typedef struct Tclient_t
{
    int id;
    char name[256];
    float buy[MONTH];
}Tclient;

void fileToTab(Tclient [MAX], char *);
int nbrClientMonth(Tclient [MAX], int);
int biggerClient(Tclient [MAX]);



int main(void)
{
    Tclient client[MAX];

    fileToTab(client, "fichierExercice2");

    printf("%d\n", nbrClientMonth(client, 10));
    printf("%d\n", biggerClient(client));

    for(int i = 0; i < nbrClient; ++i) {
        printf("id : %d nom : %s\n", client[i].id, client[i].name);
        for(int j = 0; j < MONTH; ++j)
            printf("%f ", client[i].buy[j]);
        printf("\n");
        }

    return 0;
}

int biggerClient(Tclient client[MAX])
{
    int tabClient[nbrClient];
    int biggerPos = 0;

    for(int i = 0; i < nbrClient; ++i) {
        tabClient[i] = 0;
        for(int j = 0; j < 12; ++j)
            tabClient[i] += client[i].buy[j];
    }

    for(int i = 0; i < nbrClient; ++i) {
        //printf("%d\n", client[i]);
        if(tabClient[i] > tabClient[biggerPos])
            biggerPos = i;
    }

    return(biggerPos);
}

//---------------------------- 2 ----------------------------//

int nbrClientMonth(Tclient client[MAX], int month)
{
    int nbr = 0;

    if(month > MONTH)
        return -1;
    for (int i = 0; i < nbrClient; ++i)
        if (client[i].buy[month - 1] > 0)
            ++nbr;

    return nbr;
}

//---------------------------- 1 ----------------------------//


FILE *open(char *fName)
{
    FILE *file = fopen(fName, "r");

    if (!file) {
        printf("Unable to open file %s\n", fName);
        exit(1);
    }
    return file;
}


void fileToTab(Tclient client[MAX], char *fName)
{
    FILE *file = open(fName);

    for(int i = 0; i < MAX; ++i) {
        fscanf(file, "%d", &(client[i].id));
        fscanf(file, "%s", client[i].name);
        for(int j = 0; j < MONTH; ++j)
            if(EOF == fscanf(file, "%f", &(client[i].buy[j])))
                goto end;
        ++nbrClient;
    }

    end:
    fclose(file);
}
