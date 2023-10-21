#include "vector.h"
#include "vectorList.h"
#include <stdio.h>

int main() {

    struct VectorList *vlist = createVectorList();

    printf("Size of the list is %d\n", size(vlist));
    printf("Adding Elements ... \n");

    for (int i = 0; i < 2; i++) {
        struct Vector *tmp_ptr1 = createVector(1-i, 2-i, 3-i);
        struct Vector *tmp_ptr2 = createVector(1, 2, i);
        insertElementBack(vlist, tmp_ptr1);
        insertElementFront(vlist, tmp_ptr2);
    }

    printf("Size of the list is %d\n", size(vlist));

    printf("First element is:\n");
    printVector(getElement(vlist, 0));
    printf("\nSecond element is:\n");
    printVector(getElement(vlist, 1));
    printf("\nThird element is:\n");
    printVector(getElement(vlist, 2));
    printf("\nFourth element is:\n");
    printVector(getElement(vlist, 3));
    printf("\n");
    return 0;
}