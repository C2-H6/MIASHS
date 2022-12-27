#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
    printf("Actions proposees pour la partie 3 :\n");
    printf("1. Commencer une nouvelle partie\n");
    printf("2. Lancer les des\n");
    printf("0. Quitter le jeu\n");
    printf("Que faire ?\n");
}

void zero(int nbrparties, int *lancer)
{
    int score = 0;

    if (nbrparties) {
        printf("\n\n%d parties jouer\n", nbrparties);
        for (int i = 0; i < 10; ++i) {
            score += lancer[i];
        }
        printf("La moyenne est de : %d\n\n\n", score / 10);
    }
}

int one(int *nbParties, int *nblancer)
{
    if (++(*nbParties) < 10) {
        (*nblancer) = 0;
        printf("\n\nNouvelle partie [%d/10]\n\n\n", (*nbParties));
        return 0;
    } else {
        printf("\nVous avez jouer vos 10 parties\n \t[Fin du jeux]\n\n");
        return 1;
    }
}

int two()
{
    int de1 = rand() % 6 + 1;
    int de2 = rand() % 6 + 1;
    int de3 = rand() % 6 + 1;

    int tmp = 0;
    
    if (de1 < de2 || de1 < de3) {
        if (de2 > de3) 
            de1 = de2;
        else {
            de1 = de3;
        }
    }
    if (de2 < de3)
        tmp = de2;
        de2 = de3;
        de3 = de2;

    printf("\n\nRESULTAT : {%d, %d, %d}\n\n\n", de1, de2, de3);
    if (de1 == 4 && de2 == 2 && de3 == 1)
        return 10;
    else if (de1 == 1 && de2 == 1 && de3 == 1)
        return 7;
    else if (de2 == 1 && de3 == 1)
        return de1;
    else if (de1 = de2 && de2 == de3)
        return de1;
    else if (de1 == de2 - 1 && de2 == de3 - 1)
        return 2;
    return 1;
}

int main()
{
    int Usernbr = 0;

    static  int lancer[] = {0,0,0,0,0,0,0,0,0,0};
    int nbParties = 0;
    int nblancer = 0;

    srand(time(NULL));

    do {
    menu();
    (void)scanf("%d", &Usernbr);

    switch(Usernbr) {
        case 0:
            zero(nbParties, lancer);
            return 0;   
        case 1:
            one(&nbParties, &nblancer);
            break;
        case 2:
            if (nblancer == 3)
                (void)printf("\n\nVous avez deja lancer 3 fois les des dans cette partie\n\n\n");
            else if (nbParties) {
                lancer[nbParties - 1] += two();
                (void)printf("score : %d\n\n", lancer[nbParties - 1]);
                ++nblancer;
            }
            else 
                (void)printf("\nVeuillez lancer une partie ! ! !\n\n");
            break;
        default:
            return 1;
        }
    } while(1);

    return 0;
}