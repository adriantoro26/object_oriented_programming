/**
 * Defines and typedefs
*/
typedef struct node node_t;
typedef struct queue queue_t;

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
bool isQueueEmpty(queue_t &q);
/**
 * Adds element to given queue.
 * @param q: Queue reference.
 * @param value: Value to be added to the queue.
*/
void addToQueue(queue_t &q, int value);
/**
 * Removes element from given queue.
 * @param q: Queue reference.
 * @return: Value removed.
*/
int removeFromQueue(queue_t &q);
/**
 * Displays elements in given queue.
 * @param q: Queue reference.
*/
void showQueue(queue_t &q);
/**
 * Displays last element in given queue.
 * @param q: Queue reference.
*/
void showLastInQueue(queue_t &q);