#include <stdio.h>
#include <stdlib.h>

int askNumber(char *phrase, int *frst)
{
	(void)printf("%s", phrase);
	
	if (scanf("%d", frst)) return 0;
	return 1;
}

int main()
{
	int slr, prctg;

	if (askNumber("donnez salaire\n", &slr)) return 1;
	if (askNumber("donnez pourcentage d'imposition\n", &prctg)) return 1;
	if  (0 < prctg && prctg > 100) return 1;
    
    (void)printf("salaire final : %f\n", slr * (float)prctg / 100);
    return 0;
}
