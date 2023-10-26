#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Create a 3D Vector struct on the heap with the passed arguments as values 
 * Return the pointer that points to this struct on the heap 
 */
struct Vector* createVector(int x, int y, int z)
{
    struct Vector *tmp_ptr = (struct Vector*) malloc(sizeof(struct Vector));
    checkSuccessfulMalloc(tmp_ptr);
    
    tmp_ptr->x = x;
    tmp_ptr->y = y;
    tmp_ptr->z = z;

    return tmp_ptr;
}


/**
 * Add Vector 'b' to Vector 'a' and store the result in Vector 'a'
 */
void addVector(struct Vector *a, struct Vector *b) 
{
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
}

/**
 * Helper method to print the Vector
 */
void printVector(struct Vector *a) 
{
    printf("(%d, %d, %d)", a->x, a->y, a->z);
}

/**
 * Helper method to check if a memory allocation was successful.
 * Exit the program if not.
*/
int checkSuccessfulMalloc(void *p)
{
    if (p == NULL)
    {
        printf("unsuccessful memory allocation");
        exit(1);
    }
    return 0;
}