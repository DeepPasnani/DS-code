#include<stdio.h>

void main() 
{
    char op;
    int i, j;
    int arr1[2][2], arr2[2][2], arr3[2][2];

    for(i = 0; i < 3; i++) 
    {
        for(j = 0; j < 3; j++) 
        {
            printf("Enter value for arr1[%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    for(i = 0; i < 3; i++) 
    {
        for(j = 0; j < 3; j++) 
         {
            printf("Enter value for arr2[%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &op);

    switch (op)
    {
        case '+': 
            for(i = 0; i < 3; i++) 
            {
                for(j = 0; j < 3; j++) 
                {
                    arr3[i][j] = arr1[i][j] + arr2[i][j];
                    printf("%d ", arr3[i][j]);
                }
                printf("\n");
            }
            break;

        case '-': 
            for(i = 0; i < 3; i++) 
            {
                for(j = 0; j < 3; j++) 
                {
                    arr3[i][j] = arr1[i][j] - arr2[i][j];
                    printf("%d ", arr3[i][j]);
                }
                printf("\n");
            }
            break;

        case '*':
            for(i = 0; i < 3; i++) 
            {
                for(j = 0; j < 3; j++) 
                {
                    for(int k = 0; k < 3; k++) 
                    {
                        arr3[i][j] += arr1[i][k] * arr2[k][j];
                    }
                printf("\n");
            }
            break;

        case '/': 
            for(i = 0; i < 3; i++) 
            {
                for(j = 0; j < 3; j++) 
                {
                    if (arr2[i][j] != 0)
                        arr3[i][j] = arr1[i][j] / arr2[i][j];
                    else
                        arr3[i][j] = 0;
                    printf("%d ", arr3[i][j]);
                }
                printf("\n");
            }
            break;

        default:
            printf("Enter proper operator.\n");
            break;
    }
}
