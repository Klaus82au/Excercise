#include <stdio.h>

typedef struct qNode_s {
    int data;
    struct Node_s * next;
} Node_t;

void push(Node_t ** head, int value){
    Node_t * t = (Node_t*)malloc(sizeof(Node_t));
    t->next=*head;
    t->data=value;
    (*head)=t;
}

void traverse(Node_t * node){
    if(node){
        printf("%d\n", node->data);
        traverse(node->next);
    }
}

int main(void)
{
    Node_t * head = NULL;
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    traverse(head);
    return 0;
}

