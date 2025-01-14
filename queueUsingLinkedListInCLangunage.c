#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct node{
    int data;
    struct node* next;
};

void initialization(){
    printf("Initializing memory for queue..");
    for(int i = 0; i < 4; i++){
        sleep(1);
        printf(".");
    }
    printf("\n");
}

void insert(struct node** head, int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    if((*head) == NULL){
        initialization();
        *head = n;
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void dequeue(struct node** head){
    if(*head == NULL){
        printf("Queue is empty\n");
        return;
    }
    if((*head)->next == NULL){
        printf("Only one element is present in queue\n");
        return;
    }
    struct node* toDelete = *head;
    (*head) = (*head)->next;
    free(toDelete);
}

void peek(struct node* head){
    if(head == NULL){
        printf("Queue is empty while peeking\n");
        return;
    }
    printf("Front of the queue: %d\n", head->data);
}

void empty(struct node* head){
    if(head == NULL){
        printf("Is the queue empty? Yes\n");
        return;
    }
    printf("Is the queue empty? No\n");
}

int main(){
    struct node* head = NULL;
    empty(head);
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    peek(head);
    dequeue(&head);
    peek(head);
    empty(head);

    return 0;
}