#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

typedef struct single_linked_list_t {
    int n;
    struct single_linked_list_t* next;
} single_linked_list_t;

extern void add_front_single_list(int n);
extern void add_back_single_list(int n);
extern int remove_from(int index);
extern int insert_from(int index, int n);
extern void print_single_list();
extern void destroy_single_list();

extern single_linked_list_t* get_single_list_head();
extern single_linked_list_t* get_single_list_tail();

single_linked_list_t* create_single_list_node(int n);

#endif