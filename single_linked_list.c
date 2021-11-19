#include <stdio.h>
#include <stdlib.h>
#include "single_linked_list.h"

static single_linked_list_t* head = 0;

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
    } else {
        node->next = head;
        head = node;
    }
}

void add_back_single_list(int n) {
    single_linked_list_t* node = create_single_list_node(n);

    if(!head) {
        head = node;
    } else {
        single_linked_list_t* curr = head;
        while(curr) {
            if(!curr->next) {
                curr->next = node;
                break;
            }
            curr = curr->next;
        }
    }
}

void destroy_single_list() {
    single_linked_list_t* curr = head;

    while(curr) {
        single_linked_list_t* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}

void print_single_list() {
    single_linked_list_t* curr = head;

    while(curr) {
        printf("[Single List Node %p] Value: %d, Next: %p\n", (void *) curr, curr->n, (void *) curr->next);
        curr = curr->next;
    }
}