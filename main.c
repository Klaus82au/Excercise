#include <stdio.h>


typedef struct Node_s {
    struct Node_s * next;
    int data;
} Node_t;

void push(Node_t** head, int value){
    if ((*head)==NULL){//list is empty
        *head = (Node_t*)malloc(sizeof(Node_t));
        (*head)->data=value;
        (*head)->next=NULL;
    } else {
        Node_t * newn = (Node_t*)malloc(sizeof(Node_t));
        newn->next=*head;
        newn->data=value;
        *head = newn;
    }
}

void append(Node_t ** head, int value){
    if ((*head)==NULL){//list is empty
        *head = (Node_t*)malloc(sizeof(Node_t));
        (*head)->data=value;
        (*head)->next=NULL;
    } else {
        Node_t * last = (*head);
        while (last->next) {
            last=last->next;
        }
        last->next=(Node_t*)malloc(sizeof(Node_t));
        last->next->next=NULL;
        last->next->data=value;
    }
}

int deleteByValue(Node_t ** head, int value){
   if(head){
       Node_t* tPrev = (*head);
       Node_t* tCurr = (*head)->next;
       while((*tPrev).next){
           if(tCurr->data==value){
               tPrev->next=tCurr->next;
               free(tCurr);
               return 0;//found and deleted
           }
           tPrev=tCurr;
           tCurr=tPrev->next;
       }
       return -1;//not found
   }
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
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    append(&head, 10);
    append(&head, 9);
    append(&head, 8);
    traverse(head);
    deleteByValue(&head, 8);
    traverse(head);
    return 0;
}

