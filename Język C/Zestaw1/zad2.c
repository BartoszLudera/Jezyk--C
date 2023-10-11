#include <stdio.h>
#include <math.h> //bibiolteka zawierajaca funkcje sqrt() czyli pierwiastek
int main()
{
    int a, b, c, d;          //wspolczynniki rownania kwadratowego, delta
    float delta, x1, x2, x3; //delta po pierwiastkowaniu, roziwania rownaia
    //interaktywne pytania do uzytkowanika o podanie rownania kwadratowego
    printf("Podaj wspolczynnik a: ");
    scanf("%d", &a);
    if (a == 0)
    {
        printf("Wspolczynnik a nie moze byc rowny 0! \n");
        return 0;
    }
    printf("\nPodaj wspolczynnik b: ");
    scanf("%d", &b);

    printf("\nPodaj wspolczynnik c: \n");
    scanf("%d", &c);

    //obliczanie delty ze wzoru delta=b*b-4*a*c
    d = (b * b) - (4 * a * c);
    if(d<0)//jesli delta<0 rownanie nie ma rozwian
    {
        printf("Delta wynosi: %d - rownanie nie ma rozwiazan!",d);
        return 0;
    }
    //oblicznie pierwiastka z delty sqrt()
    delta=sqrt(d);

    //oblicznie x1 oraz x2 (lub x3 w przypadku kiedy jest tylko 1 rozwiazanie)
    if (delta == 0)
    {
        x3 = (-b) / (2 * a);
        printf("\nRownanie ma rozwiaznie rowne: %f", x3);
    }
    else
    {
        x1 = ((-b) - delta) / (2 * a);
        x2 = ((-b) + delta) / (2 * a);

        printf("\nRownanie ma rozwiaznia rowne: %f oraz %f", x1, x2);
    }

    return 0;
}
