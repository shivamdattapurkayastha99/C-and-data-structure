// Implementation of stack
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct Stack{
    int top;
    unsigned capacity;
    int *array;
};
struct Stack *createstack(unsigned capacity)
{
    struct Stack *stack=(struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity=capacity;
    stack->top=-1;
    stack->array=(int *)malloc(stack->capacity*sizeof(int));
    return stack;
}
int isFull(struct Stack *stack)
{
    return stack->top==stack->capacity-1;

}
int isEmpty(struct Stack *stack)
{
    return stack->top==-1;
}
void push(struct Stack *stack,int item)
{
    if(isFull(stack))
    return;
    stack->array[++stack->top]=item;
    printf("The data pushed to stack is %d\n",item);

}
int pop(struct Stack *stack)
{
    if(isEmpty(stack))
    return -1;
    return stack->array[stack->top--];

}
int peek(struct Stack *stack)
{
    if(isEmpty(stack))
    return -1;
    return stack->array[stack->top];
}
int stackBottom(struct Stack *stack)
{
    if(isEmpty(stack))
    return -1;
    return stack->array[0];
}
int main(int argc, char const *argv[])
{
  struct Stack *stack=createstack(5);
  push(stack,10);
  push(stack,20);
  push(stack,30);
  printf("Popped element from stack is %d\n",pop(stack));
  printf("Topmost element of stack is %d\n",peek(stack));
  printf("Bottom element of stack is %d\n",stackBottom(stack));
    return 0;
}
