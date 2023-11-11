#include <stdio.h>

int main() 
{
    // Define the array length, the array itself and a pointer to it.
    int len = 10;
    int arr[len];
    int *arr_ptr = &arr[0];

    // Fill the array with integers
    for (int i = 0; i < len; i++)
    {
        arr[i] = i;
    }

    // Print the array in reverse Order using the bracket syntax.
    printf("Array in reverse Order using [ ] :");
    for (int i = len-1; i >= 0; i--)
    {
        printf("%d, ", arr[i]);
    }

    printf("\n"); // newline

    // Print the array in reverse Order using pointer arithmetic.
    printf("Array in reverse Order using pointer arithmetic:");
    for (int i = len-1; i >= 0; i--)
    {
        printf("%d, ", *(arr_ptr + i));
    }

    printf("\n");

    return 0; // Tells the OS that this programm exited successfully.
}