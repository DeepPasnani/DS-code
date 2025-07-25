#include<stdio.h>

void main() 
{
    char op;
    int i, j;
    int arr1[3][3], arr2[3][3], arr3[3][3];

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

    printf("Enter operator (+, -, *, t): ");
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
                    arr3[i][j] = 0;
                    for(int k = 0; k < 3; k++) 
                    {
                        arr3[i][j] += arr1[i][k] * arr2[k][j];
                    }
                    printf("%d ", arr3[i][j]);
                }
                printf("\n");
            }
            break;

        case 't':
            for(i = 0; i < 3; i++) 
            {
                for(j = 0; j < 3; j++) 
                {
                    printf("%d ", arr1[i][j]);
                }
                printf("\n");
            }

            printf("Transpose of the asked matrix is: \n");

            for(i = 0; i < 3; i++) 
            {
                for(j = 0; j < 3; j++) 
                {
                    arr3[i][j] = arr1[j][i];

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
