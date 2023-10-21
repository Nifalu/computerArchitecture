#pragma once

struct Vector
{
    int a;
    int b;
    int c;
};

struct Vector* createVector(int a, int b, int c);

void deleteVector(struct Vector *v);

void addVector(struct Vector *a, struct Vector *b);

void printVector(struct Vector *v);
