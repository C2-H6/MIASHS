#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#define FNAME "tmprt"
#define BUFSIZE 255

int *fileToTab(char *);
void tabToFile(char *, int *);
int *bubbleSort(int *, int);

int main(void)
{
    tabToFile("FichierRangs.txt", bubbleSort(fileToTab(FNAME), 11));
    return 0;
}



//---------------------------- algo trie ----------------------------//



int *bubbleSort(int *tab, int n)
{
    static int tabGen[12] = {0, 1 , 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int tmpValue;

    for(int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
                if (tab[i] > tab[j]) {
                    tmpValue = tab[i];
                    tab[i] = tab[j];
                    tab[j] = tmpValue;

                    tmpValue = tabGen[i];
                    tabGen[i] = tabGen[j];
                    tabGen[j] = tmpValue;
                }
            }
    }
                
    return tabGen;
}



//---------------------------- interaction fichier ----------------------------//



FILE *open(char *fName, char *mode)
{
    FILE *file = fopen(fName, mode);

    if (!file) {
        printf("Unable to open file %s\n", FNAME);
        exit(1);
    }
    return file;
}

int *fileToTab(char *fName)
{
    FILE *file = open(fName, "r");
    char buff[BUFSIZE];
    static  int tab[12];

    for (int i = 0; fgets(buff, BUFSIZE, file); ++i)
            tab[i] = atoi(buff);
    fclose(file);
    return tab;
}

void tabToFile(char *fName, int *tab)
{
    FILE *file = open(fName, "w");

    for(int i = 0; i < 12; ++i)
        fprintf(file, "%d\n", tab[i]);

    fclose(file);
}

