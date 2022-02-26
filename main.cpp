#include <iostream>
#include "queue/queue.h"

/**
 * Defines and typedefs
*/
#define NUMBERS_QTY 2
typedef enum {
    INPUT,
    OPERATION
}states_t;

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

    int product = 1;
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
 * Performs Sum, Substraction, Product and Division on the last two elements
 * in the given queue.
 * @param q: Queue  reference
 * @param op: Operation to be executed.
 * @param result: Stores the operation result
 * @return True if successful, false otherwise (e.g., Unsupported operation).
*/
bool executeOperation(queue_t &q, char op, int &result){
    bool res = true;

    switch(op){
        case '+':
            result = sum(q);
        break;

        case '-':
            result = substraction(q);
        break;

        case '*':
            result = product(q);
        break;

        case '/':
            result = division(q);
        break;

        default:
            res = false;
        break;
    }
    return res;
}

/**
 * Application entrypoint
*/
int main(){

    /**
     * Queue defined
    */
    queue_t q = {
        .head = NULL,
        .tail = NULL
    };
    /**
     * State machine state
    */
    states_t state = INPUT;

    int numbersInserted = 0;

    while(true){
        /**
         * States
        */
        char temp;
        int value, result;
        char operation;

        printf("> ");

        switch (state){
            case INPUT:
                scanf("%i", &value);
                scanf("%c", &temp);
                addToQueue(q, value);
                showLastInQueue(q);
                numbersInserted++;

                if (numbersInserted == NUMBERS_QTY){
                    numbersInserted = 0;
                    state = OPERATION;
                }
                break;

            case OPERATION:
            scanf("%c", &operation);
                scanf("%c", &temp);
                bool res = executeOperation(q, operation, result);

                if(res)
                    printf("%i\n", result);
                else
                    printf("Operation no valida \n");

                state = INPUT;
                break;
        }
    }
    return 0;
}