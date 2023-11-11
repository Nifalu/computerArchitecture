#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

/**
 * Helper method to print the Vector Array
*/
void printArray(struct Vector *a, int size)
{
    printf("[");
    for (int i = 0; i < size; i++) {
        printVector(a+i);
    }
    printf("]\n");
}

/**
 * Calculate and return the L2 norm of a vector.
*/
double absLength(const struct Vector *vec)
{
    return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

/**
 * Compare Method to define how Vectors are compared.
 * This method is needed for the qsort() algortithm to work.
*/
int compareVec(const void *p, const void *q) 
{
    const struct Vector *vecA = (const struct Vector *)p;
    const struct Vector *vecB = (const struct Vector *)q;
    
    double lenA = absLength(vecA);
    double lenB = absLength(vecB);

    if (lenA > lenB) return 1;
    if (lenA < lenB) return -1; 
    return 0;
}

/**
 * Write the Vector array to a file.
 * 1. Try to open the file, return early if it failed.
 * 2. Iterate through the array using pointer arithmetic and print to the file.
*/
void writeToFile(struct Vector *vec, int size)
{
    FILE *file = fopen("vectors.txt", "w");

    if (!file) // check if file is there
    {
        printf("Failed to open file");
        return;
    }

    // iterate through the array and write the vectors in the file.
    for (int i = 0; i < size; i++) 
    {
        fprintf(file, "(%d, %d, %d)\n", (vec+i)->x, (vec+i)->y, (vec+i)->z);
    }

    fclose(file);
}



int main() {

    // Fill the array with some vectors.
    struct Vector vectorArray[12];
    struct Vector *arr_ptr = &vectorArray[0];
    
    for (int i = 0; i < 12; i++)
    {
        vectorArray[i] = (struct Vector){12-i, 12-i, 12-i};
    }

    // Print the array before and after the qsort().
    printArray(arr_ptr, 12);
    qsort(vectorArray, 12, sizeof(struct Vector), compareVec);
    printArray(arr_ptr, 12);

    writeToFile(arr_ptr, 12);
}