#pragma once

struct VectorNode
{
    struct Vector *data;
    struct VectorNode *next;
};

struct VectorList
{
    struct VectorNode *head;
    struct VectorNode *tail;
    int size;
};

struct VectorList* createVectorList();

void deleteVectorList(struct VectorList *l);

int size(struct VectorList *l);

void printVectorList(struct VectorList *l);

struct Vector* getElement(struct VectorList *l, int idx);

void insertElementFront(struct VectorList *l, struct Vector *v);

void insertElementBack(struct VectorList *l, struct Vector *v);
