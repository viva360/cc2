#include <stdio.h>
#include <stdlib.h>

typedef struct MinStack {
  int capacity;
  int* elements;
  int* min_stack;
  int top;
  int min_top;
} MinStack;

MinStack* create_min_stack(int capacity) {
  MinStack* stack = (MinStack*)malloc(sizeof(MinStack));
  stack->capacity = capacity;
  stack->elements = (int*)malloc(sizeof(int) * capacity);
  stack->min_stack = (int*)malloc(sizeof(int) * capacity);
  stack->top = -1;
  stack->min_top = -1;
  return stack;
}

void push(MinStack* stack, int element) {
  if (stack->top == stack->capacity - 1) {
    printf("Overflow! Stack is already full.\n");
    return;
  }
  stack->top++;
  stack->elements[stack->top] = element;

  if (stack->min_top == -1 || element <= stack->min_stack[stack->min_top]) {
    stack->min_top++;
    stack->min_stack[stack->min_top] = element;
  }
}

int pop(MinStack* stack) {
  if (stack->top == -1) {
    printf("Underflow! Stack is empty.\n");
    return -1;
  }
  int element = stack->elements[stack->top];
  stack->top--;

  if (element == stack->min_stack[stack->min_top]) {
    stack->min_top--;
  }

  return element;
}

int top(MinStack* stack) {
  if (stack->top == -1) {
    printf("Stack is empty.\n");
    return -1;
  }
  return stack->elements[stack->top];
}

int get_min(MinStack* stack) {
  if (stack->min_top == -1) {
    printf("Stack is empty.\n");
    return -1;
  }
  return stack->min_stack[stack->min_top];
}

void display(MinStack* stack) {
  if (stack->top == -1) {
    printf("Stack is empty.\n");
    return;
  } 
    printf("Elements: ");
    for (int i = stack->top; i >= 0; i--) {
    printf(" %d", stack->elements[i]);
  }
  printf("\nMin Stack:");
  if (stack->min_top == -1) {
    printf(" Empty\n");
  } else {
    for (int i = stack->min_top; i >= 0; i--) {
      printf(" %d", stack->min_stack[i]);
    }
    printf("\n");
  }
}

void free_min_stack(MinStack* stack) {
  free(stack->elements);
  free(stack->min_stack);
  free(stack);
}

int main() {
  int capacity = 5;
  MinStack* stack = create_min_stack(capacity);

  push(stack, 10);
  push(stack, 5);
  push(stack, 3);
  push(stack, 7);
  push(stack, 2);  

  display(stack);

  int minimum = get_min(stack);
  printf("Minimum element: %d\n", minimum);

  printf("Popped ele: %d\n",pop(stack));
  printf("Popped ele: %d\n",pop(stack));
  printf("After popping: ");
  display(stack);
  printf("Minimum element after popping: %d\n", get_min(stack));


  free_min_stack(stack);

  return 0;
}