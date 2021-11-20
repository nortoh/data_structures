#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

typedef struct double_linked_list_t {
    int n;
    struct double_linked_list_t* next;
    struct double_linked_list_t* prev;
} double_linked_list_t;

extern void add_front_double_list(int n);
extern void add_back_double_list(int n);
extern void print_double_list();
extern void print_double_list_reverse();
extern void destroy_double_list();

extern double_linked_list_t* get_double_list_head();
extern double_linked_list_t* get_double_list_tail();

double_linked_list_t* create_double_list_node(int n);

#endif