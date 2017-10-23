#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct Node_s {
    struct Node_s * next;
    int data;
} Node_t;

void push(Node_t ** head, int value){
    Node_t * t = (Node_t*)malloc(sizeof(Node_t));
    t->next=*head;
    t->data=value;
    (*head)=t;
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
       return 1;//not found
   }
   return -1;//empty list
}

void traverse(Node_t * node){
    if(node){
        printf("%d\n", node->data);
        traverse(node->next);
    }
}

void traverse_reverse(Node_t * node){
    if(node){
        traverse_reverse(node->next);
        printf("%d\n", node->data);
    }
}

int count_nodes(Node_t * node){
    if(node){
        return(count_nodes(node->next) + 1);
    }
    return(0);//end of list, or emty list
}

Node_t * getN(Node_t * head, int n){
    int count=0;
    Node_t * current = head;
    while (current){
        if(count==n){
            return current;
        }
        count++;
        current=current->next;
    }
    //failure
    assert(0);
}

void insert(Node_t ** head, int pos, int value){
    Node_t * n =(Node_t*)malloc(sizeof(Node_t));
    n->data=value;
    Node_t * temp =(getN(*head, pos-1));
    n->next=temp->next;
    temp->next=n;
}

void reverse(Node_t ** head){
    Node_t * prev = NULL;
    Node_t *curr = *head;
    Node_t *next = (*head)->next;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}

Node_t * getMiddle(Node_t * head){
    Node_t * slow=head;
    Node_t * fast=head;
    int count=0;
    while(fast->next){
        if(count%2==0){
            slow=slow->next;
        }
        count++;
        fast=fast->next;
    }
    return slow;
}

int main(void)
{
    Node_t * head = NULL;
    printf("Nodes: %d\n", count_nodes(head));
    append(&head, 4);
    append(&head, 5);
    append(&head, 6);
    traverse(head);
    printf("\n");
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    traverse(head);
    printf("\n");
//    reverse(&head);
    traverse(head);
    printf("\n");
    printf("middle = %d", getMiddle(head)->data);
    return 0;
}

