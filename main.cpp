#include <iostream>

/**
 * Defines and typedefs
*/
typedef struct node node_t;
typedef struct queue queue_t;

#define NUMBERS_QTY 2

/**
 * Node structure
*/
struct node{
    int number;
    struct node *next;
    struct node *prev;
};

/**
 * Queue structure definition
*/
struct queue {
    node_t *head;
    node_t *tail;
};

int main(){

    return 0;
}