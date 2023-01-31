void echange(int *, int *);
int minimPartiel(int [], int, int);

int main(void)
{
    return 0;
}

void echange(int *a, int *b)
{
    int x = 0;

    x = *a;
    *a = *b;
    *b = x;
}

int minimPartiel(int t[], int valeur, int deb)
{
    int min = deb;

    for(int i = deb; i <= valeur; ++i)
        if ((t[i] < t[min]))
            min = i;

    return min;

}