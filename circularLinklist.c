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

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if(head == NULL){
        head = n;
        n->next = head;
        return;
    }
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insert(node* &head, int val){
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void display(node* head){
    node* temp = head;
    do{
        cout<<temp->data;
        temp = temp->next;
        if(temp != head){
            cout<<" <-> ";
        }
    }while(temp != head);
    cout<<endl;
}

void deleteNode(node* &head, int key){
    if (head == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    node* temp = head;
    if(head->data == key){
        while(temp->next != head){
            temp = temp->next;
        }

        if (temp == head) {
            delete head;
            head = NULL;
            return;
        }
        
        temp->next = head->next;
        node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;        
    }

    node* previous = NULL;
    do{
        previous = temp;
        temp = temp->next;
        if(temp->data == key){
            previous->next = temp->next;
            delete temp;
            return;
        }
    }while(temp->data != key);
    
    cout << "Key not found in the list." << endl;
}

int main(){
    node* head = NULL;
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insertAtHead(head,1);
    display(head);
    deleteNode(head,6);
    display(head);
}