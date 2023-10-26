#include "vectorList.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * Create a VectorNode on the heap containing two pointers, 
 * one to a Vector (data) and one to the next Node. 
 * Return the pointer that points to the newly created Node.
*/
struct VectorNode* createVectorNode(struct Vector *v, struct VectorNode *next) 
{
    struct VectorNode *newNode_ptr = (struct VectorNode*) malloc(sizeof(struct VectorNode));
    checkSuccessfulMalloc(newNode_ptr);
    newNode_ptr->data = v;
    newNode_ptr->next = next;

    return newNode_ptr;
}

/**
 * Create a VectorList on the heap containing two pointer 
 * to the first and last VectorNode of the list and 
 * a counter that keeps track of the list size.
*/
struct VectorList* createVectorList()
{
    struct VectorList *newList_ptr = (struct VectorList*) malloc(sizeof(struct VectorList));
    checkSuccessfulMalloc(newList_ptr); 
    newList_ptr->head = NULL;
    newList_ptr->tail = NULL;
    newList_ptr->size = 0;
    
    return newList_ptr;
}

/**
 * Returns the Element (Vector) at the given index.
 * 1. Check that the index is valid (between 0 and the list size).
 * 2. If the list is empty, just return 0.
 * 3. Iterate through the elements until we reach our index 
 * and return the pointer to that vector
*/
struct Vector* getElement(struct VectorList *l, int index)
{
    if (index < 0 || index >= size(l)) 
    {
        printf("Index is out of bounds! Index: %d", index);
        return NULL;
    }

    if (l->head == NULL)
    {
        printf("The list is empty.");
        return NULL;
    }

    struct VectorNode *curr = (l->head);
    for (int i = 0; i <= index; i++) 
    {
        curr = curr->next;
    }
    return (curr->data);
}

/**
 * Prepend an Element (Vector) to the front of the VectorList.
 * 1. Create a new VectorNode on the heap and connect it with the current head.
 * 2. Re-assign the current head pointer to our new VectorNode. (the new head)
 * 3. Increase the list size by 1.
 * 
 * If the list was empty before, let the tail also point to the new head.
*/
void insertElementFront(struct VectorList *l, struct Vector *v)
{
    struct VectorNode *newNode_ptr = createVectorNode(v, l->head);
    l->head = newNode_ptr;
    l->size++;

    if (l->tail == NULL)
    {
        l->tail = newNode_ptr;
    }
    
}

/**
 * Append an Element (Vector) to the end of the Vectorlist.
 * 1. If the list is empty, just insert it at the front using the other method.
 * 2. Else: Create a new VectorNode with the Vector and let it point to NULL
 * 3. Connect the current tail to our new Node.
 * 4. Re-assign the current tail pointer to point to the new VectorNode
 * 5. Inrease the list size by 1
*/
void insertElementBack(struct VectorList* l, struct Vector* v)
{
    if (l->head == NULL)
    {
        insertElementFront(l, v);
    }
    else
    {
        struct VectorNode *newNode_ptr = createVectorNode(v, NULL);
        l->tail->next = newNode_ptr;
        l->tail = newNode_ptr;
        l->size++;
    }
}

/**
 * Return the number of elements (VectorNodes) in the list.
*/
int size(struct VectorList *l)
{
    return l->size;
}

/**
 * Helper method to print an entire Vectorlist.
*/
void printVectorList(struct VectorList *l)
{
    struct VectorNode *tmp_ptr = l->head;
    while (tmp_ptr != NULL)
    {
        printVector(tmp_ptr->data);
        printf("\n");
        tmp_ptr = tmp_ptr->next;
    }
}

/**
 * Delete method to make sure every heap allocation was free()'d correctly
 * when a VectorList is no longer needed.
 * 1. If the list doesn't exist, just return
 * 2. Iterate over every VectorNode and free() the Vector and the Node itself.
 * 3. free() the Vectorlist struct itself.
*/
void deleteVectorList(struct VectorList *l)
{
    if (l == NULL) {
        return;
    }

    struct VectorNode *current = l->head;
    while (current != NULL) 
    {
        struct VectorNode *tmp_next = current->next;
        free(current->data);
        free(current);
        current = tmp_next;
    }
    
    free(l);
}