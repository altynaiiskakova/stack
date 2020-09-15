#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

extern int stackInit(intstack_t* self){

    self->length=10;
    self->used=0;
    self->array=(int*) malloc(sizeof(int)*10);

    if (self->array == NULL){
        return !0;
    }
    return 0;
}

extern void stackRelease(intstack_t* self){

    free(self->array);

}

extern int stackIsEmpty(const intstack_t* self){
    if (self->used != 0){
        return 0;
    }else{
        return !0;
    }
}

extern int stackTop(const intstack_t* self){

    if (stackIsEmpty(self)){
        printf("Error: Stack is empty.\n");
        return 0;
    }

    return self->array[(self->used)-1];

}

extern int stackPop(intstack_t* self){

    if (stackIsEmpty(self)){
        printf("Error: Stack is empty.\n");
        return 0;
    }
    
    int elem_on_top = self->array[self->used-1];
    --self->used;
    
    return elem_on_top;

}
extern void stackPush(intstack_t* self, int i){

    if (self->used >= self->length){
        self->length *= 2;
        int* bigger_array = (int*) malloc(sizeof(int)*(self->length));
        for (int i =0; i<self->used; ++i){
            bigger_array[i] = self->array[i];
        }

        free(self->array);
        self->array=bigger_array;
    }
    self->array[self->used] = i;
    ++self->used;
}

extern void stackPrint(const intstack_t* self){
    for (int i=self->used-1; i>=0; --i){
        printf("%i\n", self->array[i]);
    }
}


int main() {
    
    intstack_t stack;
    
    stackInit(&stack); // & stands for address

    stackPush(&stack, 1);
    stackPush(&stack, 2);
    stackPush(&stack, 3);

    while (!stackIsEmpty(&stack)){
        printf("%i\n", stackPop(&stack));
    }

    stackPop(&stack);
    stackRelease(&stack);

    return 0;
}