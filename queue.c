#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

static queue_t* head = 0;
static queue_t* tail = 0;

queue_t* create_queue_node(int key) {
    queue_t* node = malloc(sizeof(queue_t));
    node->key = key;
    node->next = 0;
    return node;
}

void push_front(int key) {
    queue_t* node = create_queue_node(key);

    if(!head) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        head = node;
    }
}

void push_back(int key) {
    queue_t* node = create_queue_node(key);

    if(!head) {
        head = node;
        tail = node;
    } else {
        queue_t* curr = head;
        while(curr) {
            if(!curr->next) {
                curr->next = node;
                tail = node;
                break;
            }
            curr = curr->next;
        }
    }
}

queue_t* front() {
    return head;
}

queue_t* back() {
    return tail;
}

void print_queue() {
    queue_t* curr = head;

    if(!curr) {
        printf("Empty!\n");
        return;
    }

    while(curr) {
        if(curr == head) printf("[head] ");
        if(curr == tail) printf("[tail] ");
        printf("[Queue Node %p] Key: %d, Next: %p\n", (void *) curr, curr->key, (void *) curr->next);
        curr = curr->next;
    }
}

queue_t* pop_queue() {
    queue_t* result = front();
    head = result->next;
    return result;
}

void destroy_queue() {
    queue_t* curr = head;

    while(curr) {
        queue_t* tmp = curr;     
        curr = curr->next;
        free(tmp);
    }
}