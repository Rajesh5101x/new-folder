#include<iostream>
using namespace std;

class node{
    public :
        int data;
        node* next;

        node(int val){
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

void append(node* &head){
    node* temp = head;
    while(temp->next->next->next->next != NULL){        //increase the "->next" to increase the value of k
        temp = temp->next;
    }
    
    node* newHead = temp->next;
    temp->next = NULL;
    
    node* last = newHead;
    while(last->next != NULL){
        last = last->next;
    }
    last->next = head;

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
    append(head);
    display(head);
}