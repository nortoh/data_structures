#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "double_linked_list.h"
#include "single_linked_list.h"

void build_single_list() {
    int max = 10;

    // Add to front
    for(int i = 0; i < max; i++) {
        add_front_single_list(rand() % 100);
    }
    
    // Add to back
    for(int i = 0; i < max; i++) {
        add_back_single_list(rand() % 100);
    }

    // Print the list
    print_single_list();

    // Destroy
    destroy_single_list();
}

void build_double_list() {
    int max = 10;

    // Add to front
    for(int i = 0; i < max; i++) {
        add_front_double_list(rand() % 100);
    }
    
    // Add to back
    for(int i = 0; i < max; i++) {
        add_back_double_list(rand() % 100);
    }

    // Print the list
    print_double_list();

    // Print the list in reverse
    printf("### Reversed ###\n");
    print_double_list_reverse();
    
    // Destroy
    destroy_double_list();
}

int main(int argc, char** argv) {
    srand(time(0));

    printf("Data Structure Playground by Christian Horton\n");

    printf("=== Single Linked List ===\n");
    build_single_list();

    printf("\n");

    printf("=== Double Linked List ===\n");
    build_double_list();
    return 0;
}