#include <stdio.h>

#define FNAME "tmprt"

void modifyFile(FILE *);

int main(void) {
    FILE *file = fopen(FNAME, "w");

    if (!file) {
        printf("Unable to open file %s\n", FNAME);
        return 1;
    }

    modifyFile(file);
    fclose(file);

    return 0;
}

void modifyFile(FILE *file)
{
    int var;
    char *mois[] = {"janvier", "fevrier", "mars", "avril", "mai", "juin",
                    "juillet", "aout", "septembre", "octobre", "novembre", "decembre"};

    for(int i = 0; i < 12; ++i) {
        printf("Donne la temperature du mois de %s\n", mois[i]);
        scanf("%d", &var);
        fprintf(file, "%d\n", var);
    }
}