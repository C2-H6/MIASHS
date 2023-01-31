int somme(int [], int);
int minim(int [], int);

int main(void)
{
    return 0;
}

int somme(int t[], int size)
{
    int som = 0;

    for(int i = 0; i <= size; ++i)
        som += t[i];

    return som;
}

int minim(int t[], int size)
{
    int min = t[0];

    for (int i = 1; i <= size; ++i)
        if(t[i] < min)
            min = t[i];

    return min;
}