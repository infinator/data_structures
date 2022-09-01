#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int is_empty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(struct stack *ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if(is_full(ptr))
    {
        printf("Stack Overflow.\n");
    }
    else 
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if(is_empty(ptr))
    {
        printf("Stack Underflow.\n");
        return -1;
    }
    else 
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct stack *ptr, int pos)
{
    int idx = ptr->top-pos+1;

    if (idx < 0)
    {
        printf("Invalid Peek.\n");
        return -1;
    }
    else
    {
        return ptr->arr[idx];
    }
}

int stack_top(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int stack_bottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main(int argc, char const *argv[])
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));

    push(sp, 50);
    push(sp, 60);
    push(sp, 70);
    push(sp, 80);

    int a = stack_top(sp);
    int b = stack_bottom(sp);
    printf("Stack Top : %d\nStack Bottom : %d\n", a, b);

    return 0;
}