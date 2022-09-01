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

int main(int argc, char const *argv[])
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 1;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));

    push(sp, 50);
    printf("%d\n", is_empty(sp));
    push(sp, 60);
    pop(sp);
    pop(sp);
    printf("%d\n", is_empty(sp));

    return 0;
}
