#include <stdio.h>            // include stdio to get commands like printf

int main() 
{
    int len = 10;             // Used to set the length of the array
    int arr[len];             // Signed integer array of size len
    int *arr_ptr = &arr[0];   // Pointer to the first element of the array  

    // Fill the array with integers from 0 to 9
    for (int i = 0; i < len; i++)
    {
        arr[i] = i;
    }

    // Print the array using the [ ] syntax
    printf("%s", "Array in reverse Order using [ ] : \0");
    for (int i = len-1; i >= 0; i--)
    {
        printf("%d, ", arr[i]);
    }

    printf("%s","\n\0"); // new line

    // Print the array using pointer arithmetic
    printf("%s", "Array in reverse Order using a pointer: \0");
    for (int i = len-1; i >= 0; i--)
    {
        printf("%d, ", *(arr_ptr + i));
    }

    printf("%s","\n\0"); // new line

    return 0; // indicates that program exited successfully
}