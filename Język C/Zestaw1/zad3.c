#include <stdio.h>
int main()
{
    /*wczytanie liczby do jakiego zakresu ma działać algorytm*/

    int size;       /*rozmiar zakresu*/
    int i, j, p, y; /*zmienne do pętli*/
    printf("Podaj zakres dla jakiego podac liczby pierwsze: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("rozmiar nie może być <0 lub =0\n");
        return 0;
    }

    if (size == 1)
    {
        printf("Brak liczb pierwszych dla podanego zakresu.\n");
        return 0;
    }

    int number[size]; /*okreslenie tablicy 1 do okreslonego zakresu*/
    for (y = 0; y < size; y++)
    {
        number[y] = 1;
    }

    /*algorytm Eratostenesa*/

    for (i = 2; i <= size; i++)
    {
        for (j = i * i; j <= size; j += i)
        {
            number[j] = 0; /*jesli liczbe trzeba wykreslic to program przpisuje danemu numerowi w tablicy 0*/
        }
    }

    /*przerobienie 1 na liczby stosujac numer w tablicy w ktorej znajdowala sie dana 1*/
    for (p = 2; p <= size; p++)
    {
        if (number[p] == 1)
        {
            printf("%d ", p);
        }
    }

    printf("\n");

    return 0;
}
