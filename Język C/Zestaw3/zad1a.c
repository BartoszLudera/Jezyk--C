#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Konwersja_Dec_Bin(unsigned dec, char *bin)
{
    int temp, i;
    int minBin = 0;

    while (pow(2, minBin) <= dec) /*petla liczaca ile najmniej miejsc moze zajac liczba w systemie bin*/
    {
        minBin++;
    }

    bin = malloc(sizeof(char) * minBin); /*alokacja pamieci dla tablicy bin ktora przechowa zamieniona liczbe*/

    i = minBin - 1;
    while (dec > 0)
    {

        if (dec % 2 == 0)
        {
            bin[i] = '0';
            dec = dec / 2;
        }
        else
        {
            bin[i] = '1';
            dec = (dec - 1) / 2;
        }
        i--;
    }

    for (temp = 0; temp < minBin; temp++) /*petla wypisuje wartosci tablicy bin[] od 0 do najwiekszej*/
    {
        printf("%c", bin[temp]);
    }
    printf("\n");
}

int main()
{
    char *bin;
    unsigned dec;
    printf("Podaj liczbe dec: ");
    scanf("%d", &dec);

    printf("Twoja liczba w systemie bin wynosi: ");
    Konwersja_Dec_Bin(dec, bin);

    return 0;
}