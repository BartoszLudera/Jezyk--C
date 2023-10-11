#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    double numbers[1000], n, suma = 0.0f, srednia, odchy = 0.0f, odchylenie; /*numbers - tablica ze wszystkimi liczbami wczytanymi z pliku, n - zmienna pomocnicza, odchy - zmienna pomocnicza do liczenia odchylenia*/
    int i = 0,p; /*i - licznik,p-zmienna do pętli*/

    /*wczytanie danych z pliku*/
    FILE *file=stdin;
    
    while (fscanf(file, "%lf", &n) != EOF) /*jesli znak bedzie == EOF koniec petli*/
    {
        numbers[i] = n; /*wpisanie numerow do tablicy*/
        suma = suma + n;
        i++;
    }
    fclose(file); /*zamkniecie pliku*/

    /*srednia arytmetyczna*/
    srednia = (suma / i);
    printf("\nSrednia %d liczb wynosi: %lf\n", i, srednia);

    /*odchylenie standardowe*/
    for (p = 0; p < i; p++)
    {
        odchy = odchy + pow(numbers[p] - srednia, 2); /*obliczenie pomocnicze*/
    }
    odchylenie = sqrt(odchy / i);
    printf("\nOdchylenie standardowe z %d liczb wynosi: %lf\n", i, odchylenie);

    return 0;
}