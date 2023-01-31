#include <stdio.h>

int main() {
    int a, b = 0;
    
    scanf("%d %d", &a, &b);
    
    if (a == 0) {
        printf("erreur pas de solution\n");
    } else {
        printf("x = %d\n", (a * -1 + b * -1));
    }

    return 0;
}