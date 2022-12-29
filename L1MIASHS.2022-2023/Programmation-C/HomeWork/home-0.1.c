
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h> 

typedef struct data_s
{
    int nbrGame;
    int min;
    int max;
    int moyenne;
}data;

void printData(data try)
{
    (void)printf("Vous avez jouer %d parties\n", try.nbrGame);
    (void)printf("Vous avez eu besoin de %d essaies minimum\n", try.min);
    (void)printf("Vous avez eu besoin de %d essaies maximum\n", try.max);
    (void)printf("Vous avez eu besoin de %d essaies en moyenne\n", try.moyenne / try.nbrGame);
}

int genNbr(void)
{
    return rand() % 9;
}

char *initTab(void)
{
    static char tab[5];
    size_t ctn = 0;
    
    for(size_t i = 0; i < 5; ++i) {
        do {
            tab[i] = genNbr();
            ctn = 0;
            for(size_t j = 0; j < i; ++j)
                if (tab[i] == tab[j])
                    ctn = 1;
        } while(ctn);
    }
    return tab;
}

void changeStat(int nbr, data *try)
{
    ++(try->nbrGame);

    if (!(try->min))
        try->min = nbr;
    else if (nbr < try->min)
        try->min = nbr;

    if (nbr > try->max)
        try->max = nbr;

   try->moyenne += nbr;
}

int same(char *tab, int i, int nbr)
{
    for (int j = 0; j < 5; ++j)
        if (tab[j] == nbr)
            return 1;
    return 0;
}

int abyssOfTheGame(char *tab, int nbr)
{
    int tabCmp[] = {10000, 1000, 100, 10, 1};
    int count = 0;

    for (size_t i = 0; i < 5; ++i) {
            if (nbr / tabCmp[i] % 10 == tab[i]) {
                (void)printf("+");
                ++count;
            } 
            else if (same(tab, i, (nbr / tabCmp[i] % 10))) {
                printf("~");
            } else
                printf("-");      
        }
    printf("\n");
    return count;
}

int gameImself(char *tab)
{
    int nbr = 0, nbrTry = 0;

    #if DEBUG
    (void)printf("Le nombre a chercher : [");
    for(size_t j = 0; j < 5; ++j)
        (void)printf("%d", tab[j]);
    (void)printf("]\n");
    #endif

    do {
        (void)printf("essayer de trouver le nombre :\n");
        (void)scanf(" %d[0-9]", &nbr);

        ++nbrTry;
    } while(abyssOfTheGame(tab, nbr) != 5);
      
    return nbrTry;
}

void game(data *try)
{
    srand(time(NULL));
    char *tab = initTab();

    changeStat(gameImself(tab), try);
}

int main(void)
{
    char *aff = NULL; 
    data try = {0,0,0,0};

    do {
        game(&try);
        (void)printf("voulez vous rejouez [y/n]\n");
        (void)scanf("%ms[a-z]", &aff); // gestion d'erreur
    } while(!(strcmp("y", aff)));

    if (aff)free(aff);
    printData(try);

    return 0;
}