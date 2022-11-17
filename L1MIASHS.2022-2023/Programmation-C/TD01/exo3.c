#include <stdio.h>
#include <stdlib.h>

int askNumber(char *phrase, int *frst, int *scnd, int *thrd)
{
	(void)printf("%s", phrase);
	
	if (scanf("%d %d %d", frst, scnd, thrd)) return 0;
	return 1;
}

int main()
{
	int n1, n2, n3, c1, c2, c3;

	if (askNumber("donnez 3 nombres\n", &n1, &n2, &n3)) return 1;
	if (askNumber("donnez 3 coefficient\n", &c1, &c2, &c3)) return 1;
	
	(void)printf("moyenne : %d\n", ((n1 * c1) + (n2 * c2) + (n3 * c3)) / (c1 + c2 + c3));

	return 0;
}
