#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A 3D Vector struct
struct Vector 
{
    int a;
    int b;
    int c;
};

// Helper method to print a vector
void printVec(struct Vector *a) 
{
    printf("(%d, %d, %d), ", a->a, a->b, a->c);
}

// Helper method to print the Vector Array
void printArray(struct Vector *a, int size)
{
    printf("[");
    for (int i = 0; i < size; i++) {
        printVec(a+i);
    }
    printf("]\n");
}

// Calculate L2 form of a vector
double absLength(const struct Vector *a)
{
    return sqrt(a->a * a->a + a->b * a->b + a->c * a->c);
}

// Compare Vectors, interesting parameter declaration to work with qsort()
int compareVec(const void *p, const void *q) 
{
    const struct Vector *a = (const struct Vector *)p;
    const struct Vector *b = (const struct Vector *)q;
    
    double lenA = absLength(a);
    double lenB = absLength(b);

    if (lenA > lenB) return 1;
    if (lenA < lenB) return -1; 
    return 0;
}

// write our vectors in a txt.
void writeToFile(struct Vector *a, int size)
{
    FILE *file = fopen("vectors.txt", "w");

    if (!file) // check if file is there
    {
        printf("Failed to open file");
    }

    // iterate through the array and write the vectors in the file.
    for (int i = 0; i < size; i++) 
    {
        fprintf(file, "(%d, %d, %d)\n", (a+i)->a, (a+i)->b, (a+i)->c);
    }

    fclose(file);
}

int main() {

    // Fill the array with some vectors.
    struct Vector vectorArray[12];
    struct Vector *arr_ptr = &vectorArray[0];
    
    for (int i = 0; i < 12; i++)
    {
        vectorArray[i] = (struct Vector){30-i, i, 2*i};
    }

    // Print the array before and after the qsort().
    printArray(arr_ptr, 12);
    qsort(vectorArray, 12, sizeof(struct Vector), compareVec);
    printArray(arr_ptr, 12);

    writeToFile(arr_ptr, 12);
}