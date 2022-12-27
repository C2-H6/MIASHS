#include <stdio.h>
#include <string.h>

#define Size 15

int main(void)
{
    char str[Size];
    long int leng = 0;
    int occ = 0;//exercice .2

    //exercice .1
    printf("Entrer une chaine de caractere : ");
    scanf("%s", str);
    leng = strlen(str);
    (void)printf("la chaine a une taille de: %ld\n", leng);

    //exercice .2
    for(size_t i = 0; i < leng; ++i)
        if(str[i] == 'E' || str[i] == 'e')
            ++occ;
    (void)printf("il y a : %d occurence\n",occ);

    //exercice .3
    for(size_t i = 0; i < leng; ++i)
        if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            str[i] = '*';
    (void)printf("%s\n", str);

    //exercice .4
    for(size_t i = 0; i < leng; ++i) {
        if(str[i] != str[leng -i -1]) {
            (void)printf("Le nombre n'est  pas un palyndrome\n");
            return 0;
           }
    }
    (void)printf("La chaine est un palyndrome\n");

    return 0;
}