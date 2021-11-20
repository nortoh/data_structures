#include "single_linked_list.h"

#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack_t {
    int key;
    struct stack_t* next;
} stack_t;

extern void insert_stack_item(int key);
extern void destroy_stack();
extern stack_t* peek_stack();
extern stack_t* pop_stack();

stack_t* create_stack_node(int key);
void print_stack();
#endif