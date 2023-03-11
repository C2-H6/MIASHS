#include <stdio.h>

void lowerCase(char *);
void composePhrase(char *);
void addWord(char *, int);


int main(void)
{
    char tab[256];

    //lowerCase(tab);
    //printf("%s", tab);
    addWord(tab, 256);
    //composePhrase(tab);
    printf("%s", tab);
    return 0;
}


void lowerCase(char *tab)
{
    for (int i = 0; tab[i]; ++i)
        if (tab[i] >= 'A' && tab[i] <= 'Z')
            tab[i] += 32;
}

void addWord(char *tab, int size)
{
    int pos = 0;
    char buff[256];
    char cmp = 'n';

    do {
        printf("Entrez un mot\n");
        scanf("%s", buff);
        for(int i = 0; buff[i]; ++i)
            tab[pos++] = buff[i];

        printf("Voullez vous continuer ? [y/n]\n");
        scanf(" %c", &cmp);
        if (cmp != 'y')
            break;
        tab[pos++] = ' ';
    } while(1);


}

void composePhrase(char *tab)
{
    int i = 1;

    if (tab[0] >= 'a' && tab[0] <= 'z')
            tab[0] -= 32;
    while (tab[i++])
        if (tab[i] >= 'a' && tab[i] <= 'z' && (tab[i - 1] == ' ' || tab[i + 1] == ' '))
            tab[i] -= 32;
    if (tab[i - 2] >= 'a' && tab[i - 2] <= 'z')
            tab[i - 2] -= 32;
}