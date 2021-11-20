#ifndef __QUEUE_H__
#define __QUEUE_H__
typedef struct queue_t {
    int key;
    struct queue_t* next;
} queue_t;

extern queue_t* front();
extern queue_t* back();
void print_queue();
extern void push_back(int key);
extern void push_front(int key);
extern void destroy_queue();
extern queue_t* pop_queue();
#endif
