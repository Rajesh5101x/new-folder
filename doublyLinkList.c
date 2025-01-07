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

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    if (head != NULL) {
        n->next = head;
        head->previous = n;
    }
    head = n;
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

void deleteNode(node* &head, int key) {
    if (head == NULL) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }

    node* temp = head;

    if (head->data == key) {
        head = head->next;
        head->previous = NULL;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node with value " << key << " not found.\n";
        return;
    }

    if (temp->next != NULL) {
        temp->next->previous = temp->previous;
    }
    if (temp->previous != NULL) {
        temp->previous->next = temp->next;
    }

    delete temp;
}

int main(){
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insertAtHead(head,7);
    display(head);
    deleteNode(head,7);
    display(head);
}