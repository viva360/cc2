#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100
//stack using dynamic array
struct Stack {
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
// check whether stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}
// check whether stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
// Insertion in stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->array[++stack->top] = item;
}
//Deletion in stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return 0;
    }
    return stack->array[stack->top--];
}
// function to get a postfix expression, evaluate the expression and return result
int evaluatePostfix(const char* postfix) {
    struct Stack* stack = createStack(MAX_SIZE);
    int i, operand1, operand2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(stack, ch - '0'); // Convert character digit to integer
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 0;
            }
            push(stack, result);
        }
    }  

    result = pop(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter postfix expression: ");
    scanf("%s",postfix);

    int result = evaluatePostfix(postfix);
        printf("Result: %d\n", result);
    

    return 0;
}
