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

void insert(node* &head,int val){
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

node* mergePointer(node* &head1, node* &head2){
    node* temp1 = head1;
    node* temp2 = head2;
    node* dummy = new node(-1);
    node* merged = dummy; 

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data < temp2->data) {
            merged->next = temp1;
            temp1 = temp1->next;
        } else {
            merged->next = temp2;
            temp2 = temp2->next;
        }
        merged = merged->next;
    }

    while(temp1 != NULL) {
        merged->next = temp1;
        temp1 = temp1->next;
        merged = merged->next;
    }
    while(temp2 != NULL) {
        merged->next = temp2;
        temp2 = temp2->next;
        merged = merged->next;
    }
 
    return dummy->next;
}

node* mergeRec(node* &head1, node* &head2){
    if (head1 == NULL) return head2; 
    if (head2 == NULL) return head1;

    node* dummy = new node(-1);
    if(head1->data < head2->data){
        dummy->next = head1;
        mergeRec(head1->next, head2);
    }else{
        dummy->next = head2;
        mergeRec(head1, head2->next);
    }
    return dummy->next;
}

node* mergeRec2(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    if (head1->data < head2->data) {
        head1->next = mergeRec(head1->next, head2);
        return head1; 
    } else {
        head2->next = mergeRec(head1, head2->next);
        return head2;
    }
}

int main(){
    node* head1 = NULL;
    insert(head1,1);
    insert(head1,3);
    insert(head1,5);
    insert(head1,7);
    display(head1);

    node* head2 = NULL;
    insert(head2,2);
    insert(head2,4);
    insert(head2,6);
    display(head2);

    display(mergePointer(head1,head2));

    display(mergeRec(head1,head2));

    display(mergeRec2(head1,head2));

    return 0;
}