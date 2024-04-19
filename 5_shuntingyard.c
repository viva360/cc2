#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CAPACITY 100  
#define MAX_EXPRESSION_SIZE 100
//Structure for Q using static array
typedef struct Queue {
  int queue[MAX_CAPACITY];
  int front;
  int rear;
  int size;
} Queue;

//structure for stack using dynamic array
struct Stack {
  int top;
  int capacity;
  int* array;
};
//create and initialise stack
struct Stack* createStack(int capacity) {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int*)malloc(stack->capacity * sizeof(int));
  return stack;
}

int stackFull(struct Stack* stack) {
  return stack->top == stack->capacity - 1;
}

int stackEmpty(struct Stack* stack) {
  return stack->top == -1;
}
void push(struct Stack* stack, int item) {
  if (stackFull(stack)) {
    printf("St  ack Overflow\n");
    return;
  }
  stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
  if (stackEmpty(stack)) {
    printf("Stack Underflow\n");
    return 0;
  }
  return stack->array[stack->top--];
}
int peek(struct Stack* stack)
{
  if(stack->top == -1)
  {
    printf("Underflow\n");
    return 0;
  }
  return stack->array[stack->top];
}
//create and initialise Q
void initializeQueue(Queue* q) {
  q->front = 0;
	
  q->rear = -1;
  q->size = 0;
}
bool qEmpty(Queue* q) {
  return q->size == 0;
}
bool qfull(Queue* q) {
  return q->size == MAX_CAPACITY;
}
void enqueue(Queue* q, int item) {
  if (qfull(q)) {
    printf("Queue is full. Cannot enqueue more elements.\n");
  } else {
    q->rear = (q->rear + 1) % MAX_CAPACITY;
    q->queue[q->rear] = item;
    q->size++;	
  }
}
int dequeue(Queue* q) {
  if (qEmpty(q)) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1; 
  } else {
    int front_element = q->queue[q->front];
    q->front = (q->front + 1) % MAX_CAPACITY;
    q->size--;
    return front_element;
  }
}

int front(Queue* q) {
  if (qEmpty(q)) {
    printf("Queue is empty. Cannot peek.\n");
    return -1;
  } else {
    return q->queue[q->front];
  }
}

void print_queue(Queue* q) {
  if (qEmpty(q)) {
    printf("Queue is empty.\n");
  } else {
    printf("Queue: ");
    int i;
    for (i = 0; i < q->size; i++) {
      printf("%d ", q->queue[(q->front + i) % MAX_CAPACITY]);
    }
    printf("\n");
  }
}
//function to return the precedence of the operator
int getOperatorPrecedence(char op) {
  switch (op) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return -1;
  }
}
// Convert infix to postfix expression using Shunting Yard algo
void infixToPostfix(char infix_expr[], char postfix_expr[]) {
  Queue operand_queue;
  struct Stack* opstack = createStack(MAX_CAPACITY);
  initializeQueue(&operand_queue);
  for (int i = 0; i < strlen(infix_expr); i++) {
    char token = infix_expr[i];

    if (isalnum(token)) {// if token is an Operand
      enqueue(&operand_queue, token);
    } else if (token == '(') {
      push(opstack,token);
    } else if (token == ')') {
      while (peek(opstack) != '(') {
        enqueue(&operand_queue, pop(opstack));
      }
      pop(opstack); // remove '('
    } else if (ispunct(token)) { // if token is an operator
      int token_precedence = getOperatorPrecedence(token);
      if(token == '+' || token == '-' || token == '*' || token == '/')
      {
      while (!stackEmpty(opstack) && getOperatorPrecedence(peek(opstack)) >= token_precedence) {
        enqueue(&operand_queue, pop(opstack));
      }
      push(opstack, token);
      }
      else if(token == '^'){
          while (!stackEmpty(opstack) && getOperatorPrecedence(peek(opstack)) > token_precedence) {
        enqueue(&operand_queue, pop(opstack));
      }
      push(opstack, token);
      }
    } else {
      printf("Error: Invalid character '%c'\n", token);
      return;
    }
  }   

  // Pop remaining operators from stack to output queue
  while (!stackEmpty(opstack)) {
    enqueue(&operand_queue, pop(opstack));
  }

  // Build postfix expression from operand queue
  int i = 0;
  while (!qEmpty(&operand_queue)) {
    postfix_expr[i++] = dequeue(&operand_queue);
  }
  postfix_expr[i] = '\0';
}

int main() {

  char infix_expr[MAX_EXPRESSION_SIZE];
  char postfix_expr[MAX_EXPRESSION_SIZE];

  printf("Enter infix expression: ");
  scanf("%s", infix_expr);

  infixToPostfix(infix_expr, postfix_expr);

  printf("Postfix expression: %s\n", postfix_expr);

  return 0;
} 