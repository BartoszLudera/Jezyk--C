#include <stdio.h>
#include <math.h>
//#define INT_SIZE sizeof(int) * 8 /* Size of int in bits */

int main()
{

    //int int_size = 8;
    int dec, index, i;
    

    // printf("======%ld",INT_SIZE);

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &dec);

    int maxBin = 0;
    while (pow(2, maxBin) <= dec)
    {
        maxBin++;
    }

    int bin[maxBin];

    index = maxBin - 1;

    while (index >= 0)
    {
        /* Store LSB of num to bin */
        bin[index] = dec & 1;

        /* Decrement index */
        index--;

        /* Right Shift num by 1 */
        dec >>= 1;
    }


    printf("Converted binary: ");
    for (i = 0; i < maxBin; i++)
    {
        printf("%d", bin[i]);
    }

    return 0;
}