#include<stdio.h>

// Call by Value
void swapVal(int x, int y)
{
    int temp = 0;
    temp = x;
    x = y;
    y = temp;
}

// Call by Reference
void swapRef(int *x, int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 1; 
    int b = 2;
    
    printf("Before swapping ( CallByValue ): %d, %d \n", a, b);
    swapVal(a, b);
    printf("After swapping ( CallByValue ): %d, %d \n", a, b);

    printf("Before swapping ( CallByReference ): %d, %d \n", a, b);
    swapRef(&a, &b);
    printf("After swapping ( CallByReference ): %d, %d \n", a, b);

    return 0;
}
