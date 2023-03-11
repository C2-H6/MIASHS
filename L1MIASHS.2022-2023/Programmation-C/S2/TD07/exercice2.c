#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 256

char *fileToTab(char [SIZE][SIZE], char *);
void printTab(char [SIZE][SIZE]);
int moyenneTab(char [SIZE][SIZE]);
int countTab(char [SIZE][SIZE], int);
void sort(char [SIZE][SIZE]);


int nbrLines(char *);
FILE *open(char *);

int main(void)
{
    char tab[SIZE][SIZE];

    fileToTab(tab ,"data");
    printTab(tab);
    printf("\n%d\n", moyenneTab(tab));
    printf("%d\n", countTab(tab, 3));

    return 0;
}

/*------------------------------------- 5 -------------------------------------*/
// As we have allocated the array imprecisely, qsort cannot function correctly.
// And as we don't know if the array is traversed with sizeof() or until there is a '\0'.

int compareStrings(const void *a, const void *b) 
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void sort(char tab[SIZE][SIZE])
{
    qsort(tab, nbrLines("data"), sizeof(tab[0]), compareStrings);
}

/*------------------------------------- 4 -------------------------------------*/

int countTab(char tab[SIZE][SIZE], int found)
{
    int nbr = 0;
    int size = nbrLines("data");

    for (int i = 0; i < size; ++i)
        if (found == strlen(tab[i]))
            ++nbr;

    return nbr;
}

/*------------------------------------- 3 -------------------------------------*/

int moyenneTab(char tab[SIZE][SIZE])
{
    int nbr = 0;
    int size = nbrLines("data");

    for (int i = 0; i < size; ++i)
        nbr += strlen(tab[i]);

    return nbr / size;
}

/*------------------------------------- 2 -------------------------------------*/

void printTab(char tab[SIZE][SIZE])
{
    
    for (int i = 0; i < nbrLines("data"); ++i)
        printf("%s", tab[i]);
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

int right(char *tab, int size)
{
    for(int i = 0; i < size - 1; ++i)
        tab[i] = '\0';
    return 1;
}

char *fileToTab(char tab[SIZE][SIZE], char *fName)
{
    FILE *file = open(fName);

    for (int i = 0; right(tab[i], 256) && fgets(tab[i], SIZE, file) != NULL; ++i);

    fclose(file);
    return NULL;
}

/*------------------------------------- 0 -------------------------------------*/

int nbrLines(char *fName)
{
    FILE *file = open(fName);
    int count = 1;
    char c;

    while ((c = fgetc(file)) != EOF)
        if (c == '\n')
            ++count;

    fclose(file);
    return count;
}