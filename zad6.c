#include <stdio.h>

int main()
{


    int x;
    scanf_s("%d", &x);
    if (x <= 0)
        printf("zakaz wpisywania pierwszej <0 !!!");

    int z;

    while (1)
    {

        scanf_s("%d", &z);
        if (z > x)
        x = z;
        if (z <= 0)
        {
            printf("%d", x);
            break;
        }

    }



}