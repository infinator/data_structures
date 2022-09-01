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

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));

    // checking if stack is empty.

    if (is_empty(s) == 1)
    {
        printf("The Stack is empty.\n");
    }
    else
    {
        printf("The Stack is not empty.\n");
    }

    // pushing an element manually.

    s->arr[0] = 4;
    s->top++;

    // checking again...

    if (is_empty(s) == 1)
    {
        printf("The Stack is empty.\n");
    }
    else
    {
        printf("The Stack is not empty.\n");
    }

    return 0;
}
