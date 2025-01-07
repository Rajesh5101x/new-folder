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

void intersection(node* &head, node* &linkHead, int k){
    for(int i = 1; i < k && head != NULL; i++){
        head = head->next;
    }
    while(linkHead->next != NULL){
        linkHead = linkHead->next;
    }

    linkHead->next = head;
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

bool checkIntersection(node* &head, node* &head2){
    int i = 0, j = 0;

    node* temp1 = head;
    node* temp2 = head2;

    while(temp1->next != NULL) {
        i++; 
        temp1 = temp1->next;
    }

    while(temp2->next != NULL) {
        j++; 
        temp2 = temp2->next;
    }

    temp1 = head;
    temp2 = head2;

    if (i > j) {
        int diff = i - j;
        for (int i = 0; i < diff; i++) {
            temp1 = temp1->next;
        }
    } else {
        int diff = j - i;
        for (int i = 0; i < diff; i++) {
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL && temp2 != NULL){
        if(temp1 == temp2){ 
            return true;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return false;
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

    node* head2 = NULL;
    insert(head2,9);
    insert(head2,10);

    intersection(head,head2,5);
    cout<<(checkIntersection(head,head2) ? "True" : "False")<<endl;

}