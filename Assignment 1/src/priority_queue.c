#include <math.h>
#include "priority_queue.h"

struct Node
{
    double value;
    int key;
    struct Node* next;
    struct Node* prev;

};
struct Node *queue = NULL; // it is your queue to work with it
struct Node *head = NULL;
int size = 0;

int insert(double value, int key)
{
    // return the exit code:
    //	0 - success
    //	1 - not enough free space in the queue
    //  2 - other

    // the queue size is 100 elements
    if (size == 100){
        return 1;
    } else {
        void *ptr = malloc(sizeof(struct Node));
        struct Node *node;
        node = (struct Node *) ptr;
        node->key = key;
        node->value = value;
        node->prev = NULL;
        node->next = NULL;
        if (size == 0) {
            queue = node;
            head = node;
            size++;
        } else {
            struct Node *runer = queue;
            while (runer != NULL) {
                if (key > runer->key)
                    break;
                runer = runer->next;
            }
            if (runer == NULL) {
                head->next = node;
                node->prev = head;
                head = head->next;
            } else {
                if (runer != queue) {
                    struct Node *pre = runer->prev;
                    runer->prev = node;
                    node->next = runer;
                    pre->next = node;
                    node->prev = pre;
                } else {
                    node->next = queue;
                    queue->prev = node;
                    queue = node;
                }
            }
            size++;
        }
        return 0;
    }
}

double extract_min()
{
    // returns the min value and delete it from queue
    // if queue is empty returns -infinity and print error message to the screen
    if (size == 0){
        printf("TRY TO EXTRACT FROM EMPTY QUEUE");
        return -INFINITY;
    } else {
        double min = head->value;
        if (size == 1) {
            free(head);
            head = NULL;
            queue = NULL;
            size--;
        } else {
            head = head->prev;
            free(head->next);
            head->next = NULL;
            size--;
        }
        return min;
    }
}

int print(){
    struct Node* runer = queue;
    while(runer != NULL){
        printf(" [key: ");
        printf("%i",runer->key);
        printf(" | val: ");
        printf("%f",runer->value);
        printf("] <-->");
        runer = runer->next;
    }
    printf("\n");
    return 0;
}

