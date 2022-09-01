#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void ll_traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int is_empty(struct node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_full(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct node *push(struct node *top, int x)
{
    if (is_full(top))
    {
        printf("Stack Overflow.\n");
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

struct node *pop(struct node *ptr)
{
    if (is_empty(ptr))
    {
        printf("Stack Underflow.\n");
    }
    else
    {
        struct node *n = ptr;
        top = (ptr)->next;
        int x = n->data;
        printf("Popped element is : %d\n", x);
        free(n);
        return ptr;
    }
}

int peek(struct node *ptr, int pos)
{
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stack_top(struct node *ptr)
{
    return ptr->data;
}

int stack_bottom(struct node *ptr)
{
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
    top = push(top, 50);
    top = push(top, 60);
    top = push(top, 70);

    ll_traverse(top);

    int x = stack_top(top);
    int y = stack_bottom(top);

    printf("Stack top : %d\nStack bottom : %d\n", x, y);

    return 0;
}