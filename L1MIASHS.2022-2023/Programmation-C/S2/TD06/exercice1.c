#include <stdio.h>
#include <stdlib.h>

#define N 9
#define M 7

int fileToTab(int [N][M], char *);
void printRoad(int [N][M]);
int migration(int *, int *);
int nbrHouse(int [N][M], int , int );
void printNbrHouse(int [N][M], int , int );
int MoreHouse(int [N][M]);
int MorePeople(int [N][M]);
int emptySpace(int [N][M]);
int everythingMatter(int *);

int main(void)
{
    int road[N][M];

    if (!fileToTab(road, "data")) {
        printf("Error reading file\n");
        return 1;
    }

    if (migration(&road[0][1], &road[0][0]))
        printf("pas de place par ici !!\n");
    
    printf("nombre maison %d\n", nbrHouse(road, 1, 1));
    printNbrHouse(road, 1, 1);

    MorePeople(road);
    MoreHouse(road);
    
    emptySpace(road);

    printf("%s\n", everythingMatter(road[1]) == 1 ? "tout existe" : "tout n'existe pas");
    printRoad(road);
    return 0;
}

/*------------------------------------- 8 -------------------------------------*/

int everythingMatter(int *road)
{
    for (int i = 0; i < N; ++i)
        if (road[i] == -1)
            return 0;
    return 1;
}

/*------------------------------------- 7 -------------------------------------*/

int emptySpace(int road[N][M])
{
    int empty = 0;

    for (int i = 1; i < N; ++i) 
        for(int j = 0; j < M; ++j)
            road[i][j] == 0 ? (++empty) : (empty);

    printf("il y a %d emplacement libre\n", empty);
    return empty;
}

/*------------------------------------- 6 -------------------------------------*/

int MorePeople(int road[N][M])
{
    int maxHab = 0;
    int maxHabIndex = 0;

    for (int i = 0; i < N; ++i) {
        int housesInRoad = 0;
        for(int j = 0; j < M; ++j)
            if (road[i][j] > 0)
                housesInRoad += road[i][j];
        if (housesInRoad > maxHab) {
            maxHab = housesInRoad;
            maxHabIndex = i;
        }
    }
    printf("La rue avec le plus grand nombre de maisons est la rue %d\n", maxHabIndex + 1);
    return maxHabIndex;
}

/*------------------------------------- 5 -------------------------------------*/

int MoreHouse(int road[N][M])
{
    int maxHouses = 0;
    int maxHousesIndex = 0;

    for (int i = 0; i < N; ++i) {
        int housesInRoad = 0;
        for(int j = 0; j < M; ++j)
            if (road[i][j] > 0)
                ++housesInRoad;
        if (housesInRoad > maxHouses) {
            maxHouses = housesInRoad;
            maxHousesIndex = i;
        }
    }
    printf("La rue avec le plus grand nombre de maisons est la rue %d\n", maxHousesIndex + 1);
    return maxHousesIndex;
}


/*------------------------------------- 4 -------------------------------------*/

void printNbrHouse(int road[N][M], int x, int y)
{
    printf("nombre maison %d\n", (x > 0 && y > 0 ? road[x - 1][y - 1] : -1));
}
/*------------------------------------- 3 -------------------------------------*/

int nbrHouse(int road[N][M], int x, int y)
{
    return x > 0 && y > 0 ? road[x - 1][y - 1] : -1;
}

/*------------------------------------- 2 -------------------------------------*/

int migration(int *frst, int *scnd) {
    return !(*scnd) && (*frst) && (*scnd) < 7 ? (++(*scnd), --(*frst), 0) : 1;
}

/*------------------------------------- 1 -------------------------------------*/


FILE *open(char *fName)
{
    FILE *file = fopen(fName, "r");

    if (!file) {
        printf("Unable to open file %s\n", fName);
        exit(1);
    }
    return file;
}

int fileToTab(int road[N][M], char *fName)
{
    FILE *file = open(fName);
    int i;

    for (i = 0; i < N; ++i)
        if (fscanf(file, "%d %d %d %d %d %d %d", &road[i][0], &road[i][1], &road[i][2], &road[i][3], &road[i][4], &road[i][5], &road[i][6]) != M)
            break;

    fclose(file);
    return (i == N) ? 1 : 0;
}

/*------------------------------------- 0 -------------------------------------*/

void printRoad(int road[N][M])
{
    for (int i = 0; i < N; ++i) {
          for (int j = 0; j < M; ++j)
            printf("%d ", road[i][j]);
        printf("\n");
    }
}