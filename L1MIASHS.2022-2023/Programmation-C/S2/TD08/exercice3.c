#include <stdio.h>
#include <string.h>

#define N 256
#define MAX_ETU 50

typedef struct {
    char nom[N];
    int nbrEtu;
    char numEtudiant[MAX_ETU][8];
} groupe_t;

void createGroupe(groupe_t *, const char *, int);
void newstudent(groupe_t *, char [8]);
void goodYear(groupe_t , int );


int main(void)
{
    groupe_t g1, g2;
    createGroupe(&g1, "les boss", 12);
    createGroupe(&g2, "non", 36);

    newstudent(&g1, "12025467");
    
    goodYear(g1, 2020);
    
    return 0;
}

void goodYear(groupe_t groupe, int annee)
{   
    for(int i = 0; i < groupe.nbrEtu; ++i)
       if(groupe.numEtudiant[i][1] == ('0' + annee % 10) && groupe.numEtudiant[i][2] == ('0' + (annee / 10) % 10))
            printf("Il vien de cette annee %s\n", groupe.numEtudiant[i]);
}

void newstudent(groupe_t *groupe, char nbr[8])
{
    strcpy(groupe->numEtudiant[groupe->nbrEtu], nbr);
    ++(groupe->nbrEtu);
}


void createGroupe(groupe_t *groupe, const char *nom, int etu)
{
    strcpy(groupe->nom, nom);
    groupe->nom[MAX_ETU - 1] = '\0';
    groupe->nbrEtu = etu;

    for(int i = 0; i < etu; ++i)
        strcpy(groupe->numEtudiant[i], "12045678");
}
