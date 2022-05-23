#include <stdio.h>
#include "stack.h"

#define SIZE 10
int main() {
    //create stack for 10 elements
    struct stack_t * stack;
    if(stack_init(&stack,SIZE) == 2){
        printf("Failed to allocate memory\n");
        return 8;
    }

    //actions
    int operation=0;
    int value;
    int error=0;
    while(1){
        printf("Co chcesz zrobic? ");
        if(scanf("%d",&operation) != 1){
            stack_free(stack);
            printf("Incorrect input\n");
            return 1;
        }

        while(getchar()!='\n') continue;

        switch(operation){
            case 0:
                stack_free(stack);
                return 0;
            case 1:
                printf("Podaj liczbe: ");
                if(scanf("%d",&value) != 1){
                    stack_free(stack);
                    printf("Incorrect input\n");
                    return 1;
                }

                while(getchar()!='\n') continue;

                error = stack_push(stack,value);
                if(error == 2){
                    stack_free(stack);
                    printf("Failed to allocate memory\n");
                    return 8;
                }
                break;
            case 2:
                value = stack_pop(stack,&error);
                if(error==2){
                    printf("Stack is empty\n");
                }else{
                    printf("%d\n",value);
                }
                break;
            case 3:
                if(stack->head == 0){
                    printf("Stack is empty\n");
                }else{
                    stack_display(stack);
                }
                break;
            default:
                printf("Incorrect input data\n");
                break;
        }
    }
}
