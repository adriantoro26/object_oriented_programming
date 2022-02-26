#include <iostream>
#include "queue.h"

bool isQueueEmpty(queue_t &q){
    return q.head == NULL;
}

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

int removeFromQueue(queue_t &q){
    int value;
    node_t *node;

    node = q.head;
    value = node->number;

    q.head = q.head->next;
    delete(node);

    return value;
}

void showQueue(queue_t &q){
    node_t *node;

    node = q.head;

    while(node != NULL){
        printf("%i\n", node->number);
        node = node->next;
    }
}

void showLastInQueue(queue_t &q){
    node_t *node;

    node = q.tail;
    printf("%i\n", node->number);
}
