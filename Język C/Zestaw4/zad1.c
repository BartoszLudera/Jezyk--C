#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LENGTH_PASSWORD 10

int main(int Argc, const char *Argv[])
{
    FILE *file1;
    FILE *file2;

    char buffer[L_tmpnam];
    char haslo[MAX_LENGTH_PASSWORD];
    char znak;
    const char *tmpname = tmpnam(buffer);
    int dlugosc_hasla, j;

    if (NULL == (file1 = fopen(Argv[1], "rb")))
        return 1;

    if (NULL == (file2 = fopen(tmpname, "wb")))
        return 1;

    printf("Podaj haslo (max 10 znakow): ");
    scanf("%s", haslo);
    dlugosc_hasla = strlen(haslo);

    j = 0;
    while ((znak = getc(file1)) != EOF)
    {
        znak ^= haslo[j % (dlugosc_hasla)];
        putc(znak, file2);
        j++;
    }

    printf("\nSzyfrowanie zakonczone\n");

    rename(tmpname, Argv[1]);


    return 0;
}