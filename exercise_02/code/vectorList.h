#pragma once

struct VectorList
{
    struct VectorList *next;
    struct VectorList *tail;
    struct Vector *v;
};

struct VectorList* createVectorList();

struct VectorList* createVectorListWithEntry(struct VectorList *next, struct VectorList *tail, struct Vector *v);

void deleteVectorList(struct VectorList *l);

int size(struct VectorList *l);

void printVectorList(struct VectorList *l);

struct Vector* getElement(struct VectorList *l, int idx);

void insertElementFront(struct VectorList *l, struct Vector *v);

void insertElementBack(struct VectorList *l, struct Vector *v);
