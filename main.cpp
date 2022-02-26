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

/**
 * Checks if given queue is empty.
 * @param q: Queue reference.
 * @return: True if empty, false otherwise.
*/
bool isQueueEmpty(queue_t &q){
    return q.head == NULL;
}
/**
 * Adds element to given queue.
 * @param q: Queue reference.
 * @param value: Value to be added to the queue.
*/
void addToQueue(queue_t &q, int value){
    node_t *const node = new(node_t);
    node->number = value;
    node->next = NULL;
    node->prev = NULL;

    if(isQueueEmpty(q))
        q.head = node;
    else
        q.tail->next = node;

    node_t *prev = q.tail;
    q.tail = node;
    q.tail->prev = prev;

}

/**
 * Removes element from given queue.
 * @param q: Queue reference.
 * @return: Value removed.
*/
int removeFromQueue(queue_t &q){
    int value;
    node_t *node;

    node = q.head;
    value = node->number;

    q.head = q.head->next;
    delete(node);

    return value;
}
/**
 * Displays elements in given queue.
 * @param q: Queue reference.
*/
void showQueue(queue_t &q){
    node_t *node;

    node = q.head;

    while(node != NULL){
        printf("%i\n", node->number);
        node = node->next;
    }
}
/**
 * Displays last element in given queue.
 * @param q: Queue reference.
*/
void showLastInQueue(queue_t &q){
    node_t *node;

    node = q.tail;
    printf("%i\n", node->number);
}

int main(){

    return 0;
}