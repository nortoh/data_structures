#include <stdio.h>
#include <stdlib.h>
#include "circular_linked_list.h"

static circular_linked_list_t* head = 0;
static circular_linked_list_t* tail = 0;

circular_linked_list_t* create_circular_list_node(int n) {
    circular_linked_list_t* node = malloc(sizeof(circular_linked_list_t));
    node->n = n;
    node->next = 0;
    node->prev = 0;
    return node;
}

void add_front_circular_list(int n) {
    circular_linked_list_t* node = create_circular_list_node(n);
    
    if(!head) {
        head = node;
    } else {
        head->prev = node;
        node->next = head;
        head = node;

        // node->prev = tail;
        // tail->next = head;
    }
}

void add_back_circular_list(int n) {
    circular_linked_list_t* node = create_circular_list_node(n);

    if(!head) {
        head = node;
    } else {
        circular_linked_list_t* curr = head;
        while(curr) {
            if(!curr->next) {
                curr->next = node;
                node->prev = curr;
                tail = node;
                break;
            }
            curr = curr->next;
        }
    }


}

void destroy_circular_list() {
    circular_linked_list_t* curr = head;

    while(curr) {
        circular_linked_list_t* tmp = curr;
        curr = curr->next;
        free(tmp);
    }
}

void print_circular_list() {
    circular_linked_list_t* curr = head;
    if(curr == tail) {
        printf("Uh\n");
    }

    while(curr) {
        if(curr == head) printf("@@@");
        if(curr == tail) printf("###");
        printf("[Circular List Node %p] Value: %d, Prev: %p Next: %p\n", (void *) curr, curr->n, (void *) curr->prev, (void *) curr->next);
        curr = curr->next;
    }
}

void print_circular_list_reverse() {
    circular_linked_list_t* curr = tail;

    while(curr) {

        if(curr)
        printf("[Circular List Node %p] Value: %d, Prev: %p Next: %p\n", (void *) curr, curr->n, (void *) curr->prev, (void *) curr->next);
        curr = curr->prev;
    }
}