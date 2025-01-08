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

/* node* changePosition(node* &head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    node* oddTail = head;

    node* evenHead = new node(-1);
    node* evenTail = evenHead;

    while(oddTail != NULL && oddTail->next != NULL){
        node* evenNode = oddTail->next;
        oddTail->next = evenNode->next;

        evenTail->next = evenNode;
        evenTail = evenNode;

        if(oddTail->next != NULL){
            oddTail = oddTail->next;
        }
    }

    evenTail->next = NULL;
    return evenHead->next;
} */

node* changePosition(node* &head){
    node* oddTail = head;

    node* evenHead = head->next;
    node* evenTail = evenHead;

    while(evenTail && evenTail->next){
        oddTail->next = evenTail->next;
        oddTail = oddTail->next;

        evenTail->next = oddTail->next;
        evenTail = evenTail->next;
    }
    oddTail->next = NULL; 
    return evenHead;
}

int main(){
    node* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    //insert(head,6);
    display(head);

    node* evenLinklist = changePosition(head);
    display(evenLinklist);
    display(head);
}