#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"

static single_linked_list_t* head = 0;
static single_linked_list_t* tail = 0;
static int size = 0;

single_linked_list_t* create_single_list_node(int n) {
    single_linked_list_t* node = malloc(sizeof(single_linked_list_t));
    node->n = n;
    node->next = 0;
    return node;
}

void add_front_single_list(int n) {
    single_linked_list_t* node = create_single_list_node(n);
    
    if(!head) {
        head = node;
        tail = head;
    } else {
        node->next = head;
        head = node;
    }
    size++;
}

void add_back_single_list(int n) {
    single_linked_list_t* node = create_single_list_node(n);

    if(!head) {
        head = node;
        tail = head;
    } else {
        single_linked_list_t* curr = head;
        while(curr) {
            if(!curr->next) {
                curr->next = node;
                tail = node;
                break;
            }
            curr = curr->next;
        }
    }
    size++;
}

single_linked_list_t* get_single_list_head() {
    return head;
}

single_linked_list_t* get_single_list_tail() {
    return tail;
}

void destroy_single_list() {
    single_linked_list_t* curr = head;

    while(curr) {
        single_linked_list_t* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
    size = 0;
}

void print_single_list() {
    single_linked_list_t* curr = head;

    while(curr) {
        printf("[Single List Node %p] Value: %d, Next: %p\n", (void *) curr, curr->n, (void *) curr->next);
        curr = curr->next;
    }
}
