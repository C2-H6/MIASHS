void verif(int *, int *);
void translater(int *, int *, int *, int *, int , int);
void grandir (int, int, int *, int *, int, int);
void translater(int *, int *, int *, int *, int, int);

int main(void)
{
    return 0;
}

void verif(int *la, int *lo)
{
    int tmp = 0;

    if (la>lo) {
        tmp = *la;
        *la = *lo;
        *lo = tmp;
    }
}

void grandirTranslater(int *ax, int *ay, int *bx, int *by, int deplx, int deply)
{
    grandir(*ax, *ay, bx, by, deplx, deply);
    translater(ax, ay, bx, by, deplx, deply);
}

void grandir (int ax, int ay, int *bx, int *by, int deplx, int deply)
{
    *bx = *bx + deplx;
    *by = *by + deply;
}

void translater(int *ax, int *ay, int *bx, int *by, int deplx, int deply)
{
    *ax += deplx;
    *ay += deply;
    *bx += deplx;
    *by += deply;
}

