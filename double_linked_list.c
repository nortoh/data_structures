#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

static double_linked_list_t* head = 0;
static double_linked_list_t* tail = 0;
static int size = 0;

double_linked_list_t* create_double_list_node(int n) {
    double_linked_list_t* node = malloc(sizeof(double_linked_list_t));
    node->n = n;
    node->next = 0;
    node->prev = 0;
    return node;
}

void add_front_double_list(int n) {
    double_linked_list_t* node = create_double_list_node(n);
    
    if(!head) {
        head = node;
    } else {
        head->prev = node;
        node->next = head;
        head = node;
    }
    size++;
}

void add_back_double_list(int n) {
    double_linked_list_t* node = create_double_list_node(n);

    if(!head) {
        head = node;
    } else {
        double_linked_list_t* curr = head;
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
    size++;
}

void destroy_double_list() {
    double_linked_list_t* curr = head;

    while(curr) {
        double_linked_list_t* tmp = curr;
        curr = curr->next;
        free(tmp);
    }

    size = 0;
}

void print_double_list() {
    double_linked_list_t* curr = head;

    while(curr) {
        printf("[Double List Node %p] Value: %d, Prev: %p Next: %p\n", (void *) curr, curr->n, (void *) curr->prev, (void *) curr->next);
        curr = curr->next;
    }
}

void print_double_list_reverse() {
    double_linked_list_t* curr = tail;

    while(curr) {
        printf("[Reversed Double List Node %p] Value: %d, Prev: %p Next: %p\n", (void *) curr, curr->n, (void *) curr->prev, (void *) curr->next);
        curr = curr->prev;
    }
}