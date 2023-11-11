#include "vector.h"
#include "vectorList.h"
#include <stdio.h>

int main() {

    struct VectorList *vlist = createVectorList();

    printf("Size of the list is %d\n", size(vlist));
    printf("Adding Elements ... \n");

    // Add Vectors to the list using both insert methods.
    for (int i = 0; i < 2; i++) {
        struct Vector *tmp_ptr1 = createVector(i, i, 10);
        struct Vector *tmp_ptr2 = createVector(10, i, i);
        insertElementBack(vlist, tmp_ptr1);
        insertElementFront(vlist, tmp_ptr2);
    }

    printf("Size of the list is %d\n", size(vlist));
    printVectorList(vlist);
    
    return 0;
}