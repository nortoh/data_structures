#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "double_linked_list.h"
#include "single_linked_list.h"
#include "circular_linked_list.h"
#include "stack.h"
#include "queue.h"

#define MAX 5

void build_single_list() {

    // Add values
    for(int i = 0; i < MAX; i++) {
        if(i % 2 == 0) {
            add_front_single_list(rand() % RAND_MAX);
        } else {
            add_back_single_list(rand() % RAND_MAX);
        }
    }

    // Print the list
    print_single_list();

    // Destroy
    destroy_single_list();
}

void build_double_list() {

    // Add values
    for(int i = 0; i < MAX; i++) {
        if(i % 2 == 0) {
            add_front_double_list(rand() % RAND_MAX);
        } else {
            add_back_double_list(rand() % RAND_MAX);
        }
    }

    // Print the list
    print_double_list();

    // Destroy
    destroy_double_list();
}

void build_circular_list() {

    // Add to front
    for(int i = 0; i < MAX; i++) {
        add_front_circular_list(rand() % RAND_MAX);
    }
    
    // Add to back
    for(int i = 0; i < MAX; i++) {
        add_back_circular_list(rand() % RAND_MAX);
    }

    // Print the list
    print_circular_list();
    
    // Destroy
    destroy_circular_list();
}

void build_stack() {

    // Add values
    for(int i = 0; i < MAX; i++) {
        insert_stack_item(rand() % RAND_MAX);
    }

    // Print the stack
    print_stack();

    stack_t* pop;

    int limit = rand() % MAX + 1;
    for(int i = 0; i < limit; i++) {
        pop = pop_stack();
        if(pop) {
            printf("Popped %p: %d\n", (void *) pop, pop->key);
            free(pop);
        }
    }
    
    // Print the stack
    printf("\n=== After Stacks Pops ===\n");
    print_stack();

    // Destroy
    destroy_stack();
}

void build_queue() {

    for(int i = 0; i < MAX; i++) {
        if(i % 2 == 0) {
            push_front(rand() & RAND_MAX);
        } else {
            push_back(rand() % RAND_MAX);
        }
    }

    print_queue();

    queue_t* pop;
    int limit = rand() % MAX + 1;
    for(int i = 0; i < limit; i++) {
        pop = pop_queue();
        printf("Popped from queue: %d (%p)\n", pop->key, pop->next);
        free(pop);
    }

    printf("\n=== After Queue Pops ===\n");
    print_queue();

    destroy_queue();
}

int main(int argc, char** argv) {
    srand(time(0));

    printf("Data Structure Playground by Christian Horton\n\n");

    printf("=== Single Linked List ===\n");
    build_single_list();

    printf("\n");

    printf("=== Double Linked List ===\n");
    build_double_list();

    printf("\n");

    // printf("=== Circular Linked List ===\n");
    // build_circular_list();

    printf("=== Stack ===\n");
    build_stack();

    printf("\n");

    printf("=== Queue ===\n");
    build_queue();

    return 0;
}