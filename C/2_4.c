#include <iostream>
#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <stdbool.h>

struct list
{
    int64_t value;
    struct list *next;
};

struct list *node_create(int64_t value)
{
    struct list *a = (struct list *)malloc(sizeof(struct list));
    a->value = value;
    a->next = NULL;
    return a;
}

void list_add_front(struct list **old, int64_t value)
{
    struct list* n = node_create(value);
    n->next = *old;
    *old = n;
}

struct list *list_reverse(const struct list *list)
{
    struct list *new_l = NULL;
    struct list *ptr = (struct list *)list;
    while (ptr)
    {
        list_add_front(&new_l, ptr->value);
        ptr = ptr->next;
    }
    return new_l;
}

struct maybe_int64
{
    bool valid;
    int64_t value;
};

struct maybe_int64 some_int64(int64_t i)
{
    return (struct maybe_int64){.valid = true, .value = i};
}

const struct maybe_int64 none_int64 = {0};

struct maybe_int64 maybe_read_int64()
{
    int64_t p = 0;
    if (scanf("%d", &p) > 0)
    {
        return some_int64(p);
    }
    return none_int64;
}

void list_destroy(struct list *list)
{
    if (list == NULL)
    {
        return;
    }
    struct list *prev = NULL;
    while ((list)->next)
    {
        prev = (list);
        list = (list)->next;
        free(prev);
    }
    free(list);
}

struct list *list_read()
{
    int64_t p = 0;
    if (scanf("%d", &p) > 0)
    {
        struct list* list = node_create(p);
        while (scanf("%d", &p) > 0)
        {
            list_add_front(&list, p);
        }
        struct list* rev_list = list_reverse(list);
        list_destroy(list);
        return rev_list;
    }
    return NULL;    
}

// struct list *list_read()
// {
//     int64_t p = 0;
//     if (scanf("%d", &p) > 0)
//     {
//         struct list list = {.value = p, .next = NULL};
//         while (scanf("%d", &p) > 0)
//         {
//             struct list li = {.value = p, .next = &list};
//             list = li;
//         }
//         return list_reverse(&list);
//     }
//     return NULL;
// }

void list_print(const struct list *l)
{
    while (l)
    {
        printf("%d", l->value);
        l = l->next;
    }
}

int main(){
    // struct maybe_int64 a = maybe_read_int64();
    // printf("%d", a.value);
    struct  list* l_one = list_read();
    list_print(l_one);

}