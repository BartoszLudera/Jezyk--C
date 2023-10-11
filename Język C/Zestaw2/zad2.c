/*
UWAGA

Program przesłałem drugi raz poniewaz za pierwszym razem nie dodałem obliczania prawdopodobientwa Rozklad Bernuliego
przez co są 2 opisy. Bardzo proszę traktowac je jako 1 cały opis

Z poważaniem, Ludera Bartosz
*/


#include <stdio.h>
#include <math.h>

int iteracyjnie(int n, int k)
{
    /* dodatkowo iteracyjnie bez trojkata pascala*/

    /* int nS = 1, kS = 1, nkS = 1;
    for (int u = 1; u <= n; u++)
    {
        nS = nS * u;
    }
    for (int r = 1; r <= k; r++)
    {
        kS = kS * r;
    }
    for (int q = 1; q <= (n - k); q++)
    {
        nkS = nkS * q;
    }
    return nS / (kS * nkS);
    */

    /*trojkat pascala iteracyjnie*/
    int tab[100][100]; /*tablica kwadratowa do 100 wartsci poniewaz z wiekszych wartosci silnia i tak przekroczy zakres int*/
    int wynik;
    int liczbyN;
    liczbyN = n;
    int i, j;
    n = n + 1;
    k = k - 1;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || i == 0)
            {
                wynik = 1;
                tab[i][j] = wynik;
            }
            else
            {
                wynik = wynik * (i - j + 1) / j;
                tab[i][j] = wynik;
            }
        }
    }
    return tab[liczbyN][k + 1];
}

int rekurencyjnie(int n, int k)
{
    if (k == n || k == 0)
        return 1;
    return rekurencyjnie(n - 1, k - 1) + rekurencyjnie(n - 1, k);
}

void Prawdopodobienstwo(int n, double p)
{
    int k;
    double wynik;

    printf("Rozklad Bernuliego dla prawdopodobienstwa sukcesu: %.2f wynosi: \n",p);
    for (k = 1; k <= n; k++)
    {
        wynik = rekurencyjnie(n, k) * pow(p, k) * pow(1 - p, n - k);
        printf("Dla k=%d - Pn(%d)=%f\n", k, k, wynik);
    }
}

int main(int narg, char *argv[])
{
    int x, n, k, metoda;
    int numberN;
    long long newton;
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
    sscanf(argv[0], "%d", &n);
    sscanf(argv[1], "%d", &k);
    numberN = n; /*przypisuje 2 zmienna z wartoscia n na wypadek jej zmiany*/

    if (n < k) /*zabezpieczenie aby n>k*/
    {
        printf("BLAD DANYCH!!! n musi byc wieksze od k");
        return 0;
    }
    if (n == k) /*jesli n=k to nawet program nie musi nic liczyc bo bedzie to zawsze 1*/
    {
        printf("Dwumian newtona (z %d nad %d) = 1 (użyta metoda: %d)\n", n, k, metoda);
        return 0;
    }

    if (metoda == 1)
    {
        newton = rekurencyjnie(n, k);
    }
    else if (metoda == 2)
    {
        newton = iteracyjnie(n, k);
    }
    else
    {
        printf("Brak takiej opcji!!!");
        return 0;
    }

    printf("Dwumian newtona (z %d nad %d) = %lld (użyta metoda: %d)\n\n", n, k, newton, metoda);

    /*prawdopodobieństwo Berliniego*/

    Prawdopodobienstwo(n, 0.5f);

    return 0;
}
