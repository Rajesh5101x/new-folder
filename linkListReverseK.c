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
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

node* reverse(node* &head, int k){
    node* previous = NULL;
    node* current = head;
    node* next;

    int count = 0;
    while(count < k && current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        count++;
    }

    if(next != NULL){
        head->next = reverse(next,k);
    }

    return previous;
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

    node* newHead = reverse(head,2);
    display(newHead);
}