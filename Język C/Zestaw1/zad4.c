#include <stdio.h>
int main()
{
    int x, y, r; //x,y - 2 liczby/ r-reszta z mod
    printf("Podaj 2 liczby do policzenia NWD: \n");
    scanf("%d %d", &x, &y);

    //zabezpieczenie aby x>y
    if (x < y)
    {
        int temp=x;
        x = y;
        y = temp;
    }

    if (y == 0) //zalozenie podane w polecniu
    {
        printf("\nNWD z podanych liczb wynosi= %d\n", x);
        return 0;
    }

    //algorytm Euklidesa
    r = x % y;
    while (r > 0)
    {
        x = y;
        y = r;
        r = x % y;
    }
    
    printf("\nNWD z podanych liczb wynosi= %d\n", y);
    return 0;
}