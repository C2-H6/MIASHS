#include <stdlib.h>
#include <stdio.h>

typedef struct fiche_s
{
    int courage;
    int force;
    int culture;
    int diplomatie;
} fiche;

int btwm(int value, int min, int max)
{
    if (value < min || value > max)
        return 1;
    return 0;
}

void classes(fiche *f)
{
    if (f->courage < 12 && f->force > 12)
        printf("guerrier\n");
    else if (0) 
        printf("barbare\n");
    else if (0)
        printf("magicien\n");
    else if (0)
        printf("marchand\n");
    else 
        printf("sans profession\n");
}

int errorManagement(fiche *f)
{
    if (btwm(f->courage, 3, 18), btwm(f->force, 3, 18), btwm(f->culture, 3, 18), btwm(f->diplomatie, 3, 18))
        return 1;
    if (f->courage + f->force + f->culture + f->diplomatie > 50)
        return 1;
    return 0;
}

int main(void)
{
    fiche *f = malloc(sizeof(fiche));

    (void)scanf("%d %d %d %d", &(*f->courage), &(f->force), &(f->culture), &(f->diplomatie));
    if (errorManagement(f)) {
        printf("fiche non valide\n");
        return 1;
    }

    classes(f);
    free(f);
    return 0;
}

