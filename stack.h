#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

/* Struktur des Stacks */

typedef struct 
{
    unsigned length;
    unsigned used;
    int* array;
} intstack_t;

/* interface */

extern int stackInit(intstack_t* self);

extern void stackRelease(intstack_t* self);

extern void stackPush(intstack_t* self, int i);

extern int stackTop(const intstack_t* self);

extern int stackPop(intstack_t* self);

extern int stackIsEmpty(const intstack_t* self);

extern void stackPrint(const intstack_t* self);

#endif
