#pragma once

struct Vector
{
    int x;
    int y;
    int z;
};

struct Vector* createVector(int x, int y, int z);

void addVector(struct Vector *a, struct Vector *b);

void printVector(struct Vector *v);

int checkSuccessfulMalloc(void *p);