#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* next;
};

void insert(struct node** head, int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    if(*head == NULL){
        *head = n;
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(struct node** head, int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->next = *head;
    *head = n;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
        if(temp != NULL){
            printf(" <-> ");
        }
    }
    printf("\n");
}

void delete(struct node** head, int key){
    if((*head)->data == key){
        struct node* toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL && temp->next->data != key){
        temp = temp->next;
    }
    struct node* toDelete = temp->next;
    if(temp->next->next == NULL){
        temp->next = NULL;
        free(toDelete);
        return;
    }
    temp->next = temp->next->next;
    free(toDelete);
}

void reverse(struct node** head, struct node* previous){
    if(*head == NULL){
        *head = previous;
        return;
    }

    struct node* next = (*head)->next;
    (*head)->next = previous;
    reverse(&next,*head);
    *head = next;
}

void main(){
    struct node* head = NULL;
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);
    insertAtHead(&head,1);
    display(head);
    delete(&head,6);
    display(head);
    reverse(&head,NULL);
    display(head);
}

