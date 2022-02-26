#include <iostream>
#include "queue.h"

#define NUMBERS_QTY 2

/**
 * Sums all numbers in the queue
*/
int sum(queue_t &q){
    node_t *node = q.tail;

    int sum = 0;
    for(int i = 0; i < NUMBERS_QTY; i++){
        sum += node->number;
        node = node->prev;
    }
    return sum;
}
/**
 * Substract last two numbers in the queue
*/
int substraction(queue_t &q){
    node_t *node = q.tail;
    return (node->prev->number - node->number);
}
/**
 * Calculates the product of all numbers in the queue
*/
int product(queue_t &q){
    node_t *node = q.tail;

    int product = 0;
    for(int i = 0; i < NUMBERS_QTY; i++){
         product *= node->number;
        node = node->prev;
    }
    return product;
}
/**
 * Divides last two numbers in the queue
*/
int division(queue_t &q){
    node_t *node = q.tail;

    return (node->prev->number / node->number);
}

/**
 * Application entrypoint
*/
int main(){

    return 0;
}