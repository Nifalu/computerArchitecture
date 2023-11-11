#include "vectorList.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


struct VectorList* createVectorList()
{
    struct VectorList *tmp_ptr = (struct VectorList*) malloc(sizeof(struct VectorList));
    tmp_ptr->next = NULL;
    tmp_ptr->tail = NULL;
    tmp_ptr->v = NULL;
    
    return tmp_ptr;
}

struct VectorList* createVectorListWithEntry(struct VectorList *next, struct VectorList *tail, struct Vector *v)
{
    struct VectorList *tmp_ptr = (struct VectorList*) malloc(sizeof(struct VectorList));
    tmp_ptr->next = next;
    tmp_ptr->tail = tail;
    tmp_ptr->v = v;
    
    return tmp_ptr;
}

void deleteVectorList(struct VectorList *l)
{
    struct VectorList *current = l;
    while (current != NULL) 
    {
        struct VectorList *tmp_next = current->next;
        free(current->v);
        free(current);
        current = tmp_next;
    }
}


// Returns pointer to vector at index
struct Vector* getElement(struct VectorList *l, int index)
{
    if (index < 0 || index > size(l)) 
    {   // Check if index is out of bounds
        printf("Index is out of bounds! Index: %d", index);
        return NULL;
    }

    if (l->v == NULL)
    {   // Check if list is empty
        printf("The list is empty.");
        return NULL;
    }

    if (index == 0)
    {   // First Element
        return (l->v);
    }

    // Iterating through the list
    struct VectorList *curr = (l->next);
    for (int i = 0; i < index; i++) 
    {
        curr = curr->next;
    }
    return (curr->v);
}


void insertElementFront(struct VectorList *l, struct Vector *v)
{
    struct VectorList *tmp_ptr = createVectorListWithEntry(l, l->tail, v);

    // When list was empty, set the tail_ptr also to the new node.
    if (l->v == NULL)
    {
        free(l->v);
        free(l);
    }

    // Insert the passed vector to that node and connect it with the head
    l = tmp_ptr;


}

void insertElementBack(struct VectorList* l, struct Vector* v)
{
    struct VectorList *tmp_ptr = createVectorListWithEntry(NULL, NULL, v);
    
    // If list was empty, let the head point to the new node.
    if (l->v == NULL)
    {
        free(l->v);
        free(l);
        l = tmp_ptr;
    }

    l->tail->next = tmp_ptr;
    l->tail = tmp_ptr;
}

int size(struct VectorList *l)
{
    struct VectorList *curr = l;
    int count = 0;
    while (curr != NULL) {
        curr = curr->next;
        count += 1;
    }
    return count;
}