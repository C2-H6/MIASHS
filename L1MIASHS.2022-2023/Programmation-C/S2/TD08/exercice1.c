
#include <stdio.h>
#include <string.h>

#define N 256

typedef struct {
    char nom[N];
    char prenom[N];
    float moyenne;
    int rang;
} etudiant_t;

void printStudent(etudiant_t);
void NomPrenom(etudiant_t *);

int main(void)
{
    etudiant_t etudiant = {"Dupond", "Olivier", 12.5, 165};

    NomPrenom(&etudiant);
    printStudent(etudiant);

    return 0;
}


void printStudent(etudiant_t etudiant)
{
    printf("nom : %s\nprenom : %s\n", etudiant.nom, etudiant.prenom);
    printf("moyenne : %f\nrang :%d\n", etudiant.moyenne, etudiant.rang);
}


void NomPrenom(etudiant_t *etudiant)
{
    char tmp[256];

    strcpy(tmp, etudiant->nom);
    strcpy(etudiant->nom, etudiant->prenom);
    strcpy(etudiant->prenom, tmp);

}
