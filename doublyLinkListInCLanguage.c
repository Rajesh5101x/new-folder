#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* previous;
    int data;
    struct node* next;
};

void insert(struct node** head, int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->previous = NULL;
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
    n->previous = temp;
}

void insertAtHead(struct node** head, int val){
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->previous = NULL;
    n->data = val;
    n->next = *head;
    if (*head != NULL) {
        (*head)->previous = n;
    }
    *head = n;
}

void delete(struct node** head, int key){
    if((*head)->data == key){
        struct node* toDelete = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->previous = NULL;
        }
        free(toDelete);
        return;
    }

    struct node* temp = *head;
    while(temp->next != NULL && temp->next->data != key){
        temp = temp->next;
        if(temp->next == NULL){
            printf("Key not found\n");
            return;
        }
    }
    struct node* toDelete = temp->next;
    if(toDelete->next){
        temp->next = toDelete->next;
        toDelete->next->previous = temp;
    }else{
        temp->next = NULL;
    }
    free(toDelete);
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

void main(){
    struct node* head = NULL;

    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    insert(&head,5);
    insert(&head,6);
    insertAtHead(&head,1);

    printf("LinkList is : ");
    display(head);

    delete(&head,10);
    printf("LinkList is : ");
    display(head);
} 