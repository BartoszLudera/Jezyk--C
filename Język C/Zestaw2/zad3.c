#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct RZYM
{
    int arab;
    char *rzym;
} rz[] = {{1000, "M"},
          {900, "CM"},
          {500, "D"},
          {400, "CD"},
          {100, "C"},
          {90, "XC"},
          {50, "L"},
          {40, "XL"},
          {10, "X"},
          {9, "IX"},
          {5, "V"},
          {4, "IV"},
          {1, "I"}};

int valueOfRome(char value)
{
    int i;
    i = 12;
    while (rz[i].rzym[0] != value)
    {
        i--;
    }
    return rz[i].arab;
}

int romeToArab(char *rome, int lenghtOfRome) /*funkcja ktora zamienia liczby rzymskie na arabskie*/
{
    int iterator;
    iterator = 0;
    int sum;
    sum = 0;

    while (iterator < lenghtOfRome)
    {

        switch (rome[iterator])
        {
        case 'I':
            if (iterator + 1 >= lenghtOfRome)
            {
                sum += valueOfRome(rome[iterator]);
                iterator++;
            }
            else if ((rome[iterator + 1] != 'V') && (rome[iterator + 1] != 'X'))
            {
                sum += valueOfRome(rome[iterator]);
                iterator++;
            }
            else
            {
                sum += valueOfRome(rome[iterator + 1]) - valueOfRome(rome[iterator]);
                iterator += 2;
            }
            break;
        case 'X':
            if (iterator + 1 >= lenghtOfRome)
            {
                sum += valueOfRome(rome[iterator]);
                iterator++;
            }
            else if ((rome[iterator + 1] != 'L') && (rome[iterator + 1] != 'C'))
            {
                sum += valueOfRome(rome[iterator]);
                iterator++;
            }
            else
            {
                sum += valueOfRome(rome[iterator + 1]) - valueOfRome(rome[iterator]);
                iterator += 2;
            }
            break;

        case 'C':
            if (iterator + 1 >= lenghtOfRome)
            {
                sum += valueOfRome(rome[iterator]);
                iterator++;
            }
            else if ((rome[iterator + 1] != 'D') && (rome[iterator + 1] != 'M'))
            {
                sum += valueOfRome(rome[iterator]);
                iterator++;
            }
            else
            {
                sum += valueOfRome(rome[iterator + 1]) - valueOfRome(rome[iterator]);
                iterator += 2;
            }
            break;

        default:
            sum += valueOfRome(rome[iterator]);
            iterator++;

            break;
        }
    }
    return sum;
}

char *arabToRome(int n) /*funkcja ktora zamienia liczby arabskie na rzyskie*/
{
    char *romeNumbers;
    int k = 0;

    romeNumbers = (char *)malloc(sizeof(char) * 10);

    while (n)
    {
        while (n < rz[k].arab)
        {
            k++;
        }
        while (n >= rz[k].arab)
        {
            strcat(romeNumbers, rz[k].rzym);
            n -= rz[k].arab;
        }
    }

    return romeNumbers;
}

int main(int argc, char const *argv[])
{
    char numberInput[100];
    int lenghOfInput = 0;
    printf("Podaj liczbe w dowolnym systemie: ");
    scanf("%s", &numberInput[0]);

    int x = 0;
    while (numberInput[x] != '\0')
    {
        x++;
        lenghOfInput++;
    }

    int isArab;

    isArab = isdigit(numberInput[0]);

    if (isArab != 0)
    {
        int liczba = 0;
        char *wynik;
        int h;
        for (h = 0; h < lenghOfInput; h++) /*h to licznik po tablicy char, zamiana tab char na int*/
        {
            liczba = liczba + (numberInput[h] - 48) * pow(10, lenghOfInput - 1 - h);
        }

        if (liczba < 0 || liczba > 3999)
        {
            printf("Liczba moze byc jedynie w zakresie od 1 do 3999.\n");
            return -1;
        }

        wynik = arabToRome(liczba);
        printf("Podana liczba w systemie rzymskim to: ");
        puts(wynik);

        printf("\n");
        free(wynik);
    }
    else
    {
        printf("Podana liczba w systemie arabskim to: %d\n", romeToArab(numberInput, lenghOfInput)); /*zamiana rome to arab*/
    }

    return 0;
}
