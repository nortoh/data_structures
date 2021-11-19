#ifndef __SINGLE_LINKED_LIST_H__
#define __SINGLE_LINKED_LIST_H__

typedef struct single_linked_list_t {
    int value;
    struct single_linked_list_t* next;
} single_linked_list_t;

extern void add(int n);

#endif