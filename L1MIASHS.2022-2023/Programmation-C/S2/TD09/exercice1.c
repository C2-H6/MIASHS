#include <stdlib.h>
#include <stdio.h>

#define MAX 50 
#define MONTH 12

int nbrClient = 0;

void fileToTab(float [MAX][MONTH], char *);
int nbrClientMonth(float [MAX][MONTH], int);
int biggerClient(float [MAX][MONTH]);
void data(float [MAX][MONTH], int [nbrClient], float [nbrClient]);




int main(void)
{
    float clientTab[MAX][MONTH];

    fileToTab(clientTab, "fichierExercice1");

    printf("nbr client pour le mois %d : %d\n", 6, nbrClientMonth(clientTab, 6));

    printf("le plus gros client est le %d\n", biggerClient(clientTab) + 1);

    int client[nbrClient];
    float month[nbrClient];
    
    data(clientTab, client, month);

    for(int i = 0; i < nbrClient; ++i)
        printf("%d %f\n", client[i], month[i]);

    return 0;
}

//---------------------------- 4 ----------------------------//

void data(float clientTab[MAX][MONTH], int moyClient[nbrClient], float moyMonth[nbrClient])
{
       for(int i = 0; i < nbrClient; ++i) {
        moyClient[i] = 0;
        moyMonth[i] = 0;
        for(int j = 0; j < 12; ++j) {
            moyClient[i] += clientTab[i][j];
            if (clientTab[i][j] > 0)
                ++moyMonth[i];
        }
        moyClient[i] /= 12;
        moyMonth[i] /= 12;
    }
}

//---------------------------- 3 ----------------------------//

int biggerClient(float clientTab[MAX][MONTH])
{
    int client[nbrClient];
    int biggerPos = 0;

    for(int i = 0; i < nbrClient; ++i) {
        client[i] = 0;
        for(int j = 0; j < 12; ++j)
            client[i] += clientTab[i][j];
    }

    for(int i = 0; i < nbrClient; ++i) {
        //printf("%d\n", client[i]);
        if(client[i] > client[biggerPos])
            biggerPos = i;
    }

    return(biggerPos);
}

//---------------------------- 2 ----------------------------//

int nbrClientMonth(float clientTab[MAX][MONTH], int month)
{
    int nbr = 0;

    if(month > MONTH)
        return -1;
    for (int i = 0; i < nbrClient; ++i)
        if (clientTab[i][month - 1] > 0)
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


void fileToTab(float clientTab[MAX][MONTH], char *fName)
{
    FILE *file = open(fName);

    for(int i = 0; i < MAX; ++i) {

        for(int j = 0; j < MONTH; ++j)
            if(EOF == fscanf(file, "%f", &clientTab[i][j]))
                goto end;
        ++nbrClient;
    }

    end:
    fclose(file);
}


