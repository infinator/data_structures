#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct my_array
{
    int total_size;
    int used_size;
    int *ptr;
};

void create_array(struct my_array *a, int t_size, int u_size)
{
    (*a).total_size = t_size;
    (*a).used_size = u_size;
    (*a).ptr = (int *)malloc(t_size * sizeof(int));
}

void set_values(struct my_array *a)
{
    int n;
    
    for (int i = 0; i < (*a).used_size; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &n);
        (*a).ptr[i] = n;
    }
}

void show_values(struct my_array *a)
{
    for (int i = 0; i < (*a).used_size; i++)
    {
        printf("%d ", (*a).ptr[i]);
    }
}

int main()
{
    struct my_array marks;

    create_array(&marks, 8, 4);
    set_values(&marks);
    show_values(&marks);
    

    return 0;
}