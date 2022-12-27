#include <stdio.h>

void menu()
{
    printf("Actions proposees :\n");
    printf("1. Afficher le texte courant\n");
    printf("2. Ajouter un mot a la fin\n");
    printf("3. Inserer un espace\n");
    printf("4. Supprimer un caractere\n");
    printf("5. Mettre une partie du texte en majuscules\n");
    printf("6. Mettre une partie du texte en minuscules\n");
    printf("0. Quitter l'application\n");
    printf("Que faire ?\n");
}

int main()
{
    int userNbr = 0;

    char txt[50];
    char newWord[50];
    int actualSize = 0;

    txt[0] = '\0';
    newWord[0] = '\0';

    printf("donne un premier mot batard\n");
    scanf("%d", )

    do {
    menu();
    (void)scanf("%d", &userNbr);

    switch(userNbr) {
        case 0:
        return 0;
            break;
        case 1:
           break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            return 1;
        }
    } while(1);

}