#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int n, i;
    double k, m, pi, x, y;
    k = 0.0;

    printf("Podaj liczbe n: ");
    scanf("%d", &n);

    srand(time(NULL));/*określenie działania generacji liczb po czasie*/

    for (i = 1; i <= n; i++)
    {
        x = rand() / (double)RAND_MAX;/*funkcja generujaca liczby*/
        y = rand() / (double)RAND_MAX;
        if (x * x + y * y <= 1)
        {
            k++;
        }
    }

    m = (double)n;
    pi = (4 * k) / m;
    printf("%lf\n", pi);
    printf("%lf\n", k);
}