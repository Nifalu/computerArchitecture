#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


struct Vector* createVector(int a, int b, int c)
{
    struct Vector *tmp_ptr = (struct Vector*) malloc(sizeof(struct Vector));
    tmp_ptr->a = a;
    tmp_ptr->b = b;
    tmp_ptr->c = c;

    return tmp_ptr;
}

void deleteVector(struct Vector *v)
{
    free(v);
    v = NULL;
}

// Method that adds vector 'b' to vector 'a'
void addVector(struct Vector *a, struct Vector *b) 
{
    a->a += b->a;
    a->b += b->b;
    a->c += b->c;
}

// Method to print a vector
void printVector(struct Vector *a) 
{
    printf("(%d, %d, %d)", a->a, a->b, a->c);
}