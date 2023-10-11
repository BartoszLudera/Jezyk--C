#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_MAX 20

int number[N_MAX] = {18, 94, 7229, 203};

int compare_max_min(const void *a, const void *b) //jesli funkcja zwroc wartosc ujemna to zamienia w lewo, jesli dodatnią to w prawo, jeśli == to nie zamienia
{
    return (*(int *)b - *(int*)a);
}

int compare_min_max(const void *a, const void *b) //jesli funkcja zwroc wartosc ujemna to zamienia w lewo, jesli dodatnią to w prawo, jeśli == to nie zamienia
{
    return (*(int *)a - *(int *)b);
}

int main(int narg, char *argv[])
{

    int metoda, c, n;
    int j, numberLen=4;

    //numberLen = strlen(number);

    metoda = 1;
    while (--narg > 0 && (*++argv)[0] == '-')
    {
        if (c = *++argv[0])
        {
            switch (c)
            {
            case 'M':
                sscanf(++argv[0], "%d", &metoda);
                break;
            default:
                printf("Nieznana opcja: -%c\n", c);
                return 1;
            }
        }
    }
    sscanf(argv[0], "%d", &n);

    if (metoda == 1)
    {
        qsort(number, numberLen, sizeof(int), compare_min_max);
    }
    else if (metoda == 2)
    {
        qsort(number, numberLen, sizeof(int), compare_max_min);
    }
    else
    {
        printf("Nieznana metoda: %d\n", metoda);
        return 3;
    }

    for (j = 0; j < numberLen; j++)
    {
        printf("%c ", number[j]);
    }

    return 0;
}
