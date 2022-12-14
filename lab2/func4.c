#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void printArray(int *arrPtr)
{
    printf("[");
    for (int i = 0; i < 10; i++)
    {
        printf("%d, ", *(arrPtr + i));
    }
    printf("]\n");
}

void func4()
{
    srand(time(NULL));
    
    int arr1[10];
    int arr2[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        arr1[i] = (rand() % 1000) + 1;
        arr2[i] = (rand() % 1000) + 1;
    }
    
    // Print initial arrays
    printArray(arr1);
    printArray(arr2);
    
    // Hypothetical array calculation: multiply every element by 2
    for (i = 0; i < 15; i++)
    {
        arr1[i] *= 2;
    }
    
    //Print modified arrays
    printf("\n");
    printArray(arr1);
    printArray(arr2);
    
    // Same situation with pointers
    int *arrPtr1;
    int *arrPtr2 = arr2;
    for (arrPtr1 = arr1; arrPtr1 < arr1 + 15; arrPtr1++)
    {
        *arrPtr1 *= 2;
    }
    
    //Print modified arrays
    printf("\n");
    printArray(arr1);
    printArray(arr2);
}
