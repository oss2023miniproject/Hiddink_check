#include <stdio.h>
int main() {
    int size;
    printf("size? ");
    scanf("%d",&size);
    for (int i = 0; i < size; i ++)
    {
        for (int j = 0; j <= i; j ++)
             printf("*");
        for (int k = 1; k < size - i; k++)
            printf(" ");
        for (int l = 1; l < size - i; l++)
            printf(" ");
        for (int m = 0; m <= i; m++)
            printf("*");
        printf("\n");
    }
    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < size - i; j++)
            printf("*");
        for (int k = 1; k <= i; k++)
            printf(" ");
        for (int l = 1; l <= i; l++)
            printf(" ");
        for (int m = 0; m < size - i; m++)
            printf("*");
 
        printf("\n");
    }
}
