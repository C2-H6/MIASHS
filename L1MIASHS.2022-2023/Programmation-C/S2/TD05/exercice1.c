//de Maeyer Ethan

#include <stdlib.h>
#include <stdio.h>

FILE *open(char *, char *);

void nameToFile(char *);
int nbrName(char *);
void copyAndVerify(char *, char *);
void isYourChildrenHere(char *);
int nbrChildrenYes(char *);

int main(void)
{
    nameToFile("fichier1");

    printf("Il y a %d nom dans le fichier\n", nbrName("fichier1"));
    copyAndVerify("fichier1", "fichier2");
    isYourChildrenHere("fichier2");

    printf("Le nombre d'enfant qui seras la :%d\n", nbrChildrenYes("fichier2"));

    return 0;
}

/*---------------------------------- part e ----------------------------------------*/

int nbrChildrenYes(char *fName)
{
    FILE *file = open(fName, "r");
    int size = nbrName(fName);
    char buffer[256];
    int tmp = 0;
    int nbr = 0;

    for (int i = 1; i < size; ++i) {
        fscanf(file, "%255s %d", buffer, &tmp);
        nbr += tmp;
    }
    fclose(file);
    return nbr;
}

/*---------------------------------- part d ----------------------------------------*/


void rewrite(char *f1, char *f2)
{
    FILE *file1 = open(f1, "r");
    FILE *file2 = open(f2, "w");
    char buffer[256];
    int size = nbrName(f1);
    int tmp;

    for (int i = 1; i < size; ++i) {
        fscanf(file1, "%255s %d", buffer, &tmp);
        fprintf(file2, "%s %d\n", buffer, tmp);
    }

    fclose(file1);
    fclose(file2);
}

void isYourChildrenHere(char *fName)
{
    FILE *file1 = open(fName, "r");
    FILE *file2 = open("tmp", "w");
    int size = nbrName(fName);
    char buffer[256];
    char enfant = 'n';
    int tmp;

    for (int i = 1; i < size; ++i) {
        fscanf(file1, "%255s %d", buffer, &tmp); 
        printf("l'enfant de %s seras il la [y/n]\n", buffer);
        scanf(" %c", &enfant);
        fprintf(file2, "%s %d\n", buffer, (enfant == 'y' ? 1 : 0));
    }

    fclose(file1);
    fclose(file2);
   


    rewrite("tmp", "fichier2");
}

/*---------------------------------- part c ----------------------------------------*/

void copyAndVerify(char *f1, char *f2)
{
    FILE *file1 = open(f1, "r");
    FILE *file2 = open(f2, "w");
    int size = nbrName(f1);
    char buffer[256];

    for (int i = 0; i < size; ++i) {
        fscanf(file1, "%255s", buffer); 
        fprintf(file2, "%s %d\n", buffer, -1);
    }

    fclose(file1);
    fclose(file2);
}

/*---------------------------------- part b ----------------------------------------*/

int nbrName(char *fName)
{
    FILE *file = open(fName, "r");
    int nbrLines = 0;
    int c;

    while ((c = getc(file)) != EOF)
        if (c == '\n')
            ++nbrLines;

    fclose(file);
    return nbrLines + 1;
}


/*---------------------------------- part a ----------------------------------------*/



void nameToFile(char *fName)
{
    FILE *file = open(fName, "w");
    char *buff;
    char tmp;

    printf("faite bien ATTENTION a remplacer les espaces par le symbole -\n\n\n");
    do { 
        printf("veuillez saisir un nom \n");
        scanf("%s", buff);
        fprintf(file, "%s\n", buff);
        printf("Voulez vous continuer ? [y/n]");
        scanf(" %c", &tmp);
    } while(tmp == 'y');

    fclose(file);
}


/*---------------------------------- tool ----------------------------------------*/


FILE *open(char *fName, char *mode)
{
    FILE *file = fopen(fName, mode);

    if (!file) {
        printf("Unable to open file %s\n", fName);
        exit(1);
    }
    return file;
}