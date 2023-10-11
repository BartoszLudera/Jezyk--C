#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int Konwersja_Dec_Bin_PrzesuniecieBitowe(unsigned dec, int *bin)
{
    int index, i, temp;
    int minBin = 0;
    while (pow(2, minBin) <= dec)/*petla liczaca ile najmniej miejsc moze zajac liczba w systemie bin*/
    {
        minBin++;
    }

    bin = malloc(sizeof(int) * minBin);/*alokacja pamieci dla tablicy bin ktora przechowa zamieniona liczbe*/

    index = minBin - 1;

    while (index >= 0)
    {
        bin[index] = dec & 1;
        index--;
        dec >>= 1;
    }

    for (temp = 0; temp < minBin; temp++)/*petla wypisuje wartosci tablicy bin[] od 0 do najwiekszej*/
    {
        printf("%d",bin[temp]);
    }
    printf("\n");
}

int main()
{
    int *bin;
    unsigned dec;
    printf("Podaj liczbe dec: ");
    scanf("%d", &dec);

    printf("Twoja liczba w systemie bin wynosi: ");
    Konwersja_Dec_Bin_PrzesuniecieBitowe(dec, bin);


    return 0;
}