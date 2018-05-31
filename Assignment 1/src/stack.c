#include <math.h>
#include "stack.h"

struct Node
{
    double value;
    struct Node* next;
    struct Node* prev;

};

struct Node* stack = NULL;
struct Node* head = NULL;
int size = 0;

int push(double value) {
    if (size == 50)
        return 1;
    else {
        void *ptr = malloc(sizeof(struct Node));
        struct Node *node;
        node = (struct Node *) ptr;
        node->value = value;
        node->next = NULL;
        node->prev = NULL;
        if (stack == NULL) {
            stack = node;
            head = node;
        } else {
            struct Node *buffer;
            if (stack == head) {
                stack->next = node;

            }
            buffer = head;
            head = node;
            head->prev = buffer;
            buffer->next = head;
        }
        size++;
        return 0;
    }



    // return the exit code:
    //	0 - success
    //	1 - not enough free space in the stack
    //  2 - other

    // the stack size is 50 elements

    /* YOUR CODE */
}

double pop()
{
    if (size == 0) {
        printf("TRY TO POP FROM EMPTY STACK");
        return -INFINITY;
    }
    double top;
    top = head->value;
    if (size == 1) {
        free(head);
        stack = NULL;
        head = NULL;
        size--;
        return top;
    } else{
        top = head->value;
        head = head->prev;
        free(head->next);
        head->next = NULL;
        size--;
        return top;
    }
    // returns top value and delete it from stack
    // if stack is empty returns -infinity and print error message to the screen
    /* YOUR CODE */
}

double peek()
{
    // just returns the top value
    // if stack is empty returns -infinity and print error message to the screen
    if (size == 0) {
        printf("TRY TO PEEK FROM EMPTY STACK");
        return -INFINITY;
    } else
        return head->value;

}

int print(){
    struct Node* runer = stack;
    while(runer != NULL){
        printf(" [");
        printf("%f",runer->value);
        printf("] -->");
        runer = runer->next;
    }
    return 0;
}
