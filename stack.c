#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

static stack_t* head = 0;

stack_t* create_stack_node(int key) {
    stack_t* node = malloc(sizeof(stack_t));
    node->key = key;
    node->next = 0;
    return node; 
}

void insert_stack_item(int key) {
   stack_t* node = create_stack_node(key);
   
   if(!head) {
       head = node;
   } else {
       node->next = head;
       head = node;
   }
}

stack_t* peek_stack() {
    return head;
}

stack_t* pop_stack() {
    stack_t* result = 0;
    
    if(head) {
        result = head;
        head = head->next;
    }

    return result;
}

void destroy_stack() {
    stack_t* curr = head;

    while(curr) {
        stack_t* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}

void print_stack() {
    stack_t* curr = head;

    while(curr) {
        printf("[Stack %p] Value: %d, Next: %p\n", (void *) curr, curr->key, (void *) curr->next);
        curr = curr->next;
    }
}