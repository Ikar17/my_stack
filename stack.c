#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int stack_init(struct stack_t **stack, int N){
    //check data
    if(stack==NULL || N<=0) return 1;

    //allocate memory
    *stack = calloc(1,sizeof(struct stack_t));
    if(*stack == NULL) return 2;

    (*stack)->data = calloc(N, sizeof(int));
    if((*stack)->data == NULL){
        free(*stack);
        *stack = NULL;
        return 2;
    }

    //update info
    (*stack)->capacity = N;
    (*stack)->head = 0;   //first free index

    return 0;
}

int stack_push(struct stack_t *stack, int value){
    //check data
    if(stack == NULL || stack->head<0 || stack->capacity <=0 || stack->head > stack->capacity || stack->data == NULL) return 1;

    //overflow
    if(stack->head == stack->capacity){
        int *temp = realloc(stack->data, (stack->capacity*2)*sizeof(int));
        if(temp==NULL) return 2;
        stack->data = temp;
        stack->capacity *= 2;
    }

    //push
    *(stack->data+stack->head) = value;
    stack->head +=1;
    return 0;
}

int stack_pop(struct stack_t* stack, int *err_code){
    //check data
    if(stack == NULL || stack->head<0 || stack->capacity <=0 || stack->head > stack->capacity || stack->data == NULL){
        if(err_code!=NULL){
            *err_code = 1;
            return 1;
        }else{
            return 1;
        }
    }

    //empty stack
    if(stack->head == 0){
        if(err_code!=NULL){
            *err_code = 2;
            return 2;
        }else{
            return 2;
        }
    }

    //pop
    if(err_code!=NULL) *err_code =0;
    stack->head -= 1;
    return *(stack->data + stack->head);
}

void stack_free(struct stack_t* stack){
    if(stack!=NULL){
        free(stack->data);
        free(stack);
    }
}

void stack_display(const struct stack_t* stack){
    if(stack != NULL && stack->head>0 && stack->capacity >0 && stack->head <= stack->capacity && stack->data != NULL){
        for(int i=stack->head-1; i>=0; i--){
            if(i==0){
                printf("%d",*(stack->data+i));
            }else{
                printf("%d ",*(stack->data+i));
            }
        }
        printf("\n");
    }
}

