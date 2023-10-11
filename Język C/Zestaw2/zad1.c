#include <stdio.h>

/*funkcja obliczajaca silnie iteracyjnie*/
double silnia_iteracyjnie(int n)
{
    long long silniaIteracyjna = 1;
    for (n; n > 0; n--)
    {
        silniaIteracyjna = silniaIteracyjna * n;
    }
    return silniaIteracyjna;
}
/*funkcja obliczjaca silnie rekurencyjnie*/
double silnia_rekurencyjnie(int n)
{
    if (n < 2)
        return 1;

    return n * silnia_rekurencyjnie(n - 1);
}

/*glowna funkcja obliczajaca silnie podana metoda*/
int main(int narg, char *argv[])
{
    int n, x, metoda,c;
    double silnia; /* zmienna double po to aby ogromne liczby(z poza zakresu np. long long) były zapisane w notaji wykladniczej*/
    metoda = 1; /*metoda domyślna*/
    while (--narg > 0 && (*++argv)[0] == '-')
    {
        if (x = *++argv[0])
        {
            switch (x)
            {
            case 'M':
                sscanf(++argv[0], "%d", &metoda);
                break;
            default:
                printf("Brak takiej opcji!!!");
                return 0;
            }
        }
    }
    sscanf(argv[0], "%d", &n); /*pobranie lczby do policzenia silni*/
    if (metoda == 1)
    {
        for (c=0;c<n;c++) 
        {
        silnia = silnia_rekurencyjnie(n);
        }
    }
    else if (metoda == 2)
    {
        for (c=0;c<n;c++) 
        {
        silnia = silnia_iteracyjnie(n);
        }
    }
    else
    {
        printf("Brak takiej opcji!!!");
        return 0;
    }
    
    printf("Wynik z %d! = %.0lf (użyta metoda: %d)\n", n, silnia, metoda);
    return 0;
}
