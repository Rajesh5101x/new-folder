#include<iostream>
using namespace std;

class node{
    public :
        node* previous;
        int data;
        node* next;

    node(int val){
        previous = NULL;
        data = val;
        next = NULL;
    }
};

void insert(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->previous = temp;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data;
        temp = temp->next;
        if(temp != NULL){
            cout<<" <-> ";
        }
    }
    cout<<endl;
}

void append(node* &head, int k){
    if (head == NULL || k <= 0) {
        return; 
    }

    node* temp = head;
    int length = 0;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    if (k >= length) {
        return;
    }

    temp = head;
    for(int i = 1; i < length - k; i++){
        temp = temp->next;
    }

    node* newHead = temp->next;
    temp->next->previous = NULL;
    temp->next = NULL;

    node* last = newHead;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = head;
    head->previous = last;
    head = newHead;
}

int main(){
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    append(head,3);
    display(head);
}