#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generator(int n) /*funkcja generujaca liczby*/
{
    double rn=0;
    for(int i=0;i<n;i++)
    {
        rn=rn+(((75 * (generator(n - 1) + 1)) % 65537) - 1);
    }
    return rn;
}


int main()
{
    double x, y, k, m, pi;
    int t, n, roznik, rZero;
    k = 0.0;

    printf("Podaj liczbe n: ");
    scanf("%d", &n);
    printf("Podaj R poczatkowe: ");
    scanf("%d", &rZero);

    for (t = 1; t < n; t++)
    {
        x = (double)generator(t + rZero) / (65535 + 1.0);
        y = (double)generator(t + rZero + 1) / (65535 + 1.0); /*do generator(t) w sensie t+1 to 1 dodane jest aby byly liczby inne niz w x*/

        if (((x * x) + (y * y)) < 1)
        {
            k++;
        }
    }

    m = (double)n;

    pi = (4 * k) / m;
    printf("%lf\n", pi);
    printf("%lf\n", k);

    return 0;
}