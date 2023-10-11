#include <stdio.h>
#include <string.h>

int main()
{
    int numbera[1000], numberb[1000], iloczyn[2000]={0};
    int i, j, przejscie;
    char a[1000], b[1000]; /*tablica char ktora przetrzymuje liczbe pobrana od uzykownika*/
    printf("Podaj 1 liczbe: ");
    scanf(" %s", a);
    printf("Podaj 2 liczbe: ");
    scanf(" %s", b);
    printf("\n");

    int lenghta = strlen(a); /*dlugosc pobranej liczby a*/
    int lenghtb = strlen(b); /*dlugosc pobranej liczby b*/

    for (i = lenghta - 1, j = 0; i >= 0; i--, j++)
    {
        numbera[j] = a[i] - 48; /*przerobienie tablicy char z liczba a na tab int*/
    }

    for (i = lenghtb - 1, j = 0; i >= 0; i--, j++)
    {
        numberb[j] = b[i] - 48; /*przerobienie tablicy char z liczba b na tab int*/
    }

    for (i = 0; i < lenghtb; i++)
    {
        for (j = 0; j < lenghta; j++)
        {
            iloczyn[i + j] += numberb[i] * numbera[j]; /*zapisanie wartosci z mnozenia liczby a*b do pomocniczej tablicy*/
            /*dlugosc tablicy musi byc 2 razy wieksza poniewaz tyle zajmie nasz wynik lub o 1 mniej*/
        }
    }

    for (i = 0; i < lenghta + lenghtb; i++)
    {
        przejscie = iloczyn[i] / 10; /*obliczamy przesuniecie czyli jezeli wynik z mnozenia przekracza 10 to przesuwamy wartosc
        do nastepnej liczby tak jak jest to w mnozeniu pisemnym (w slupku)*/
        iloczyn[i] = iloczyn[i] % 10;
        iloczyn[i + 1] = iloczyn[i + 1] + przejscie;
    }

    for (i = lenghta + lenghtb; i >= 0; i--)
    {
        if (iloczyn[i] > 0) /*jezeli wartosc iloczyn[i]==0 to w tedy nie ma przesuniecia*/
            break;
    }
    printf("Wynik mnozenia podanych liczb to: ");
    for (; i >= 0; i--)
    {
        printf("%d", iloczyn[i]);
    }
    printf("\n");
    return 0;
}
