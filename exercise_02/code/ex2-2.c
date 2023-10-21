#include "vector.h"
#include <stdio.h>


int main() 
{
    struct Vector *a = createVector(1, 5, 3);    // initialize two vectors
    struct Vector *b = createVector(1, 2, 3);
    addVector(a, b);
    printVector(a);
    printf("\n");

    return 0;
}
