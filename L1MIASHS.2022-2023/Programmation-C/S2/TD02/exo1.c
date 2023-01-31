int dureHmns(int, int, int);
void dureeSec(int , int *, int *, int *);

int main(void)
{
    return 0;
}

int dureHmns(int h, int mn, int s)
{
    return (s + (mn * 60) + (h * 3600));
}

void dureeSec(int d, int *h, int *mn, int *s)
{
    *mn =  d / 60;
    *s = d % 60;
    *h = *mn / 60;
    *mn = *mn % 60; 
}