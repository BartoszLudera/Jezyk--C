#include <stdio.h>

char *tydzien[] = {"Poniedzialek", "Wtorek", "Sroda", "Czwartek", "Piatek", "Sobota", "Niedziela"}; /*tablica z nazwami dni tygodnia*/

int liczbaDni[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}; /*tablica z liczba dni od początku roku (nieprzestepnego) dla kolejnych miesiecy*/



int przestepnyG(int rok) /*czy przestepny dla kalendarza gregorjanskiego*/
{
    return ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0);
}
int przestepnyJ(int rok) /*czy przestepny dla kalendarza julianskiego*/
{
    return (rok % 4 == 0);
}

int dzienTygodnia(int dzien, int miesiac, int rok, int typ) /*dla podanej daty wyznacza dzien tygodnia gdzie pon=0, niedz=6*/
{
    int dzienRoku;
    int yy, c, g;
    int wynik;
    int rPrzestepny;

    if (typ == 1)
    {
        rPrzestepny = przestepnyG(rok);
    }
    else if (typ == 0)
    {
        rPrzestepny = przestepnyJ(rok);
    }

    dzienRoku = dzien + liczbaDni[miesiac - 1];
    if ((miesiac > 2) && rPrzestepny == 1)
        dzienRoku++;

    yy = (rok - 1) % 100;
    c = (rok - 1) - yy;
    g = yy + (yy / 4);
    wynik = (((((c / 100) % 4) * 5) + g) % 7);/*dzien tygodnia dla 1 sycznia*/
    wynik += dzienRoku - 1;
    wynik %= 7;

    return wynik;
}

int main()
{
    int day, month, year, type;

    printf("Podaj dzien: ");
    scanf("%d", &day);
    printf("Podaj miesiac: ");
    scanf("%d", &month);
    printf("Podaj rok: ");
    scanf("%d", &year);
    printf("Podaj typ kalendarza (0=julianski/1=gregorianski): ");
    scanf("%d", &type);
    if ((day < 0) || (day > 32))
    {
        printf("Zle dane wejsciowe (zly dzien)\n");
        return 0;
    }
    if ((month < 0) || (month > 13))
    {
        printf("Zle dane wejsciowe (zly miesiac)\n");
        return 0;
    }
    if ((year < 0) || (year > 10000))
    {
        printf("Zle dane wejsciowe (zly rok)\n");
        return 0;
    }
    if (type == 1 || type == 0)
    {
    }
    else
    {
        printf("\nZly typ kalendarza, zostanie przyjety kalendarz gregorianski\n");
        type = 1;
    }

    int wynik;
    wynik = dzienTygodnia(day, month, year, type);
    printf("\nDzien tygodnia dla daty %d-%d-%d to: %s\n", day, month, year, tydzien[wynik]);

    return 0;
}
