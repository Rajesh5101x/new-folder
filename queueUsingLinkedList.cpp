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



void insert(node** head, int val){
    node* n = new node(val);
    if(*head == NULL){
    *head = n;
    return;
}

node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head) {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
        if (temp != NULL) {
            cout << " <-> ";
        }
    }
    cout << endl;
}

void peek(node* head) {
    if (head == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Front: " << head->data << endl;
}

void deleteFromFront(node** head) {
    if (*head == NULL) {
        cout << "Queue is empty. Cannot delete." << endl;
        return;
    }

    node* toDelete = *head;
    *head = (*head)->next;
    delete toDelete;
}

bool empty(node* head){
    return (head == NULL);
}


int main(){
    node* head = NULL;
    cout<<(empty(head) ? "Queue is empty" : "Queue is not empty")<<endl;
    insert(&head,1);
    insert(&head,2);
    insert(&head,3);
    insert(&head,4);
    display(head);
    peek(head);
    deleteFromFront(&head);
    peek(head);
    cout<<((empty(head)) ? "Queue is empty" : "Queue is not empty")<<endl;


}