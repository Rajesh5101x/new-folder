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

void insertAtHead(nod* &head, int val){
    nod* n = new nod(val);
    n->next = head;
    head = n;
}

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

bool search(nod* head, int key){
    nod* temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
         temp = temp->next;
    }
    return false;
}

void deleteNodeAtHead(nod* &head){
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    nod* toDelete = head;
    head = head->next;
    delete toDelete;
}

void deleteNode(nod*& head, int val) {
    if (head == NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    if (head->data == val) {
        deleteNodeAtHead(head);
        return;
    }

    nod* temp = head;
    while (temp->next != NULL && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        cout << "Value " << val << " not found in the list." << endl;
        return;
    }

    nod* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

//itterative way of reversing a linklist
nod* reverse(nod* &head){
    nod* previous = NULL;
    nod* current = head;
    nod* next;

    while(current != NULL){
        next = current->next;
        current->next = previous;

        previous = current;
        current = next;
    }
    head = previous;
    return previous;
}

//recursive way of reversing a linklist
nod* recRevese(nod* &head, nod* previous, nod* current) {
    if (current == NULL) {
        head = previous; 
        return head;
    }

    nod* next = current->next;
    current->next = previous;
    return recRevese(head, current, next);
}

nod* recREVERSE(nod* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    nod* tempHead = recREVERSE(head->next);
    head->next->next = head;
    head->next = NULL;

    return tempHead;
}

int main(){
    nod* head = NULL;
    insert(head,1);
    insert(head,2);
    insertAtHead(head,7);
    insert(head,3);
    insert(head,4);
    cout<<"Original linklist : ";
    display(head);

    //reversing node using itteration
    nod* newHead = reverse(head);
    cout<<"Reversing : ";
    display(newHead);

    //reversing node using recursion
    nod* newRecHead = recRevese(head,NULL,head);
    cout<<"Reversing : ";
    display(newRecHead);

    //searching node
    cout<<"Searching 3 : "<<(search(head,3)?"True":"False")<<endl;

    //deleting node
    cout<<"Deleting 3 : ";
    deleteNode(head,3);
    display(head);

    cout<<"Deleting head 7 : ";
    deleteNode(head,7);
    display(head);

    cout<<"Deleting the head : ";
    deleteNodeAtHead(head);
    display(head);

    //reversing node using recursion
    nod* newRECHead = recREVERSE(head);
    cout<<"Reversing : ";
    display(newRECHead);    
}