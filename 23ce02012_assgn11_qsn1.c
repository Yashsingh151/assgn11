#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

struct Stack {
    int top;
    char array[STACK_SIZE];
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

int isFull(struct Stack* stack) {
    return stack->top == STACK_SIZE - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

int main() {
    char input[100];
    printf("Input a string: ");
    scanf("%s", input);

    struct Stack stack;
    initializeStack(&stack);

    for (int i = 0; i < strlen(input); i++)
        push(&stack, input[i]);

    printf("Reversed string using a stack is: ");
    while (!isEmpty(&stack))
        printf("%c", pop(&stack));
    printf("\n");

    return 0;
}