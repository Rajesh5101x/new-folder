#include<iostream>
using namespace std;

class nod{
    public :
        int data;
        nod* next;

        nod(int val){
            data = val;
            next = NULL;
        }
};

void insert(nod* &head, int val){

    nod* n = new nod(val);

    if(head == NULL){
        head = n;
        return ;
    }

    nod* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(nod* head){
    nod* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    nod* head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    display(head);
}