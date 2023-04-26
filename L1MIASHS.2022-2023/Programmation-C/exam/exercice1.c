#include <stdlib.h>
#include <stdio.h>

#define R 17 //nbr de range
#define S 6 //siege par range
#define T 2 //travee


void charge(char *, int[R][S]);
void nombrePlaces(int [R][S], int *, int *);
int estVide(int [R][S], int );



int enfantSeul(int [R][S], int );
int ComptePlacesAdulte(int [R][S], int);


int main(void)
{
    int avion[R][S];//la structure de donne de l'avion
    int nbrEnfant = 0;//la variable qui garde en memoire le nbr d'enfant
    int nbrLibre = 0;//la variable qui garde en memoire le nbr de siege vide

    charge("Fichier1.txt", avion);//fonction qui charge l'avion

    // fonction qui donne le nombre d'enfant et de place vide
    nombrePlaces(avion, &nbrEnfant, &nbrLibre);

    
    //affiche l'avion
    /*for (int i = 0; i < R; ++i) {
        for(int j = 0; j < S; ++j)
            printf("%d", avion[i][j]);
        printf("\n");
    }*/

    //affiche le nombre d'enfant et de place libre
    printf("\nnbr enfant : %d\nnbr libre : %d\n", nbrEnfant, nbrLibre);

    //print conditionelle qui affiche si la range donne en parametre est vide
    printf("la ligne %d %s\n", 0, estVide(avion, 0) ? "est vide" : "n'est pas vide");

    //part A exercice 3
    printf("dans la rangee %d %s\n", 3, enfantSeul(avion, 3) ? "il y a au moin 1 enfant seul" : "pas d'enfant ou enfant accompagner");

    //part C exercice 3
    printf("dans la trave %d il y a %d adultes\n", 5, ComptePlacesAdulte(avion, 5));
}

/*-------------------------- partC exercice 3--------------------------*/


/*
Justification de choix :
Le choix depend de comment on traite les donnee 

La methode del'exercice 1 est plus legere dans la memoire
nous n'avons besoin de s'avoir ici que vide ou plenne
Alors int avion[][] me parait etre un meilleur choix
*/

int ComptePlacesAdulte(int avion[R][S], int travee)
{
    int compteur = 0;

    for(int i = 0; i < R; ++i)
        if (avion[i][travee] == 1)
            ++compteur; 
    return compteur;
}


/*-------------------------- partA exercice 3--------------------------*/


/*
Justification de choix :
Le choix depend de comment on traite les donnee 

La methode del'exercice 1 est plus legere dans la memoire
et comme dans se cas nous n'avons besoin que de check les places d'une meme ligne
Alors int avion[][] me parait etre un meilleur choix
*/

int enfantSeul(int avion[R][S], int rang)
{
    int enfant = 0;

    for(int j = 0; j < S; ++j)
        if (avion[rang][j] == 2)
            ++enfant;
    for(int j = 0; j < S; ++j)
        if (enfant && avion[rang][j] == 1)
            return 0;
    return 1;
}

/*-------------------------- part3 --------------------------*/

//return 0 si une des place est prise
//return 1 si la range est vide
int estVide(int avion[R][S], int line)
{
    for (int j = 0; j < S; ++j)
        if (avion[line][j] != 0)
            return 0;
    return 1;
}

/*-------------------------- part2 --------------------------*/

void nombrePlaces(int avion[R][S], int *nbrEnfant, int *nbrLibre)
{
            for (int i = 0; i < R; ++i) {
                for(int j = 0; j < S; ++j) {
                if (avion[i][j] == 0)//0 veut dire que la place est vide
                    ++(*nbrLibre);
                else if (avion[i][j] == 2)//2 veut dire que la place est prise par un enfant
                    ++(*nbrEnfant);
                }
            }
}

/*-------------------------- part1 --------------------------*/


//fonction a part pour catch open car open peut echouer et va preferer fermer le programme
// plutot que de le faire crash
FILE *open(char *fName)
{
    FILE *file = fopen(fName, "r");

    if (!file) {
        printf("Unable to open file %s\n", fName);
        exit(1);
    }
    return file;
}

//charge le fichier dans int avion[][]
//en fonction de R et de S
void charge(char *fName, int avion[R][S])
{
    FILE *file = open(fName);

    for (int i = 0; i < R; ++i)
        for(int j = 0; j < S; ++j)
            fscanf(file,"%d", &(avion[i][j]));

    fclose(file);
}
