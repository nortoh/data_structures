#ifndef __CIRCULAR_LINKED_LIST_H__
#define __CIRCULAR_LINKED_LIST_H__

typedef struct circular_linked_list_t {
    int n;
    struct circular_linked_list_t* next;
    struct circular_linked_list_t* prev;
} circular_linked_list_t;

extern void add_front_circular_list(int n);
extern void add_back_circular_list(int n);
extern void print_circular_list();
extern void print_circular_list_reverse();
extern void destroy_circular_list();

circular_linked_list_t* create_circular_list_node(int n);

#endif