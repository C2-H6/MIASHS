#include <stdio.h>
#define F 100
#define R 17 //nombre de rangées
#define S 6 // nombre de places par rangée

typedef struct{
  int r; // numéro de rangée
  char s; // lettre du siège
  char t; // travée : 'g', 'd' dans le cas de deux travées
  int res; // statut de la réservation
}Tsiege;

int ChargeFichier(char[F], Tsiege[R*S]);
void Affichage(Tsiege[R*S]);


int reservationType(Tsiege [R*S], int , char);
int allReserved(Tsiege [R*S], int);


void deuxPlacesLibres(Tsiege [R*S], Tsiege *, Tsiege *);


int main(){
  Tsiege t[R*S];
  int res;
 
  res = ChargeFichier("Fichier1.txt",t);
  
  
  
  if(res==1) {

    Affichage(t);
    // part1
    printf("La range 2 F a comme type de reservation : %d\n", reservationType(t, 2, 'F'));
    
    // part2
    printf("la ligne %d est %s\n", 0, allReserved(t, 0) == 1 ? "libre" : "pas libre");

    //part B exercice 3
    Tsiege place1;
    Tsiege place2;
    deuxPlacesLibres(t, &place1, &place2);
    printf("voici deux places cote a cote\n");
    printf("%d %c %c %d\n",place1.r, place1.s, place1.t, place1.res);
    printf("%d %c %c %d\n",place2.r, place2.s, place2.t, place2.res);

  }
    return(0);
}


/*-------------------------- partB exercice 3--------------------------*/


/*
Justification de choix :
la structure contient deja les information comme les lettres et les numeros de places
elle est donc un meilleur choix pour des questions de facilite d'utilisation

Meme si toujours moins optimal en terme de donne stocke
*/

void deuxPlacesLibres(Tsiege t[R*S], Tsiege *place1, Tsiege *place2)
{

    for (int i = 0; i < (R * S - 1); ++i)
        if (t[i].res == 0 && t[i + 1].res == 0 && t[i].r == t[i + 1].r) {
            *place1 = t[i];
            *place2 = t[i+1];
        }

}

/*-------------------------- part2 --------------------------*/

int allReserved(Tsiege tab[R*S], int numRange)
{
    //permet de trouver la range dans la memoire en le multipliant par le nombre de range
    int debut = numRange * S;
    int fin = debut + S;//tout est a la suite dans la memoire donc on incremente simplement

    for (int i = debut; i < fin; ++i)
        if (tab[i].res != 0)
            return 0;

    return 1;
}

/*-------------------------- part1 --------------------------*/

int reservationType(Tsiege tab[R*S], int nbrRange, char lettreRange)
{
    //comme les donne ne sont pas a la suite pour trouver la valeur il faut
    //considerer la lettre comme un num par exemple A = 0
    //nbrRange * S pour avoir notre multiple de range
    //lettrerange - valeur ascii de de A
    return tab[nbrRange * S + (lettreRange - 'A')].res;
}

/*-------------------------- donner par le cour --------------------------*/


int ChargeFichier(char nomf[F], Tsiege tab[R*S]){
  FILE *f;
  int r[S];
  int rangee;
  int i;
  char lettre;
  int res; //variable qui mémorise l'état de la réservation
  f=fopen(nomf,"r");
  if(f!=NULL){
    i=0;
    rangee=0;
    lettre='A'; // pour les "lettres"
    fscanf(f,"%d",&res); // lecture de la première valeur du fichier
    while(!feof(f)){
      tab[i].r=i/6;
      tab[i].res=res;
      tab[i].s=lettre;
      if((lettre-'A'<=S/2-1))
	tab[i].t='g';
      else
	tab[i].t='d';
      fscanf(f,"%d",&res);
      i++;
      lettre++;
      if((lettre-'A')%S==0){
	rangee++;
	lettre='A';
      }
    }
    return(1);
  }
  else{
    return(0);
  }
}

void Affichage(Tsiege tab[R*S]){
  int i,j;

  for(i=0;i<R*S;i++){
    printf("%d %c %c %d\n",tab[i].r, tab[i].s, tab[i].t,tab[i].res);
    }
}
