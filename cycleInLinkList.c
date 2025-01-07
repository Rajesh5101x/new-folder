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
            cout<<"->";
        }
    }
    cout<<endl;
}

void makeCycle(node* &head, int point){
    node* temp = head;
    node* startNode;
    int count = 1;

    while(temp->next != NULL){
        if(count == point){
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool checkCycle(node* head){
    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow){
            return true;
        }
    }
    return false;
}


void removeCycle(node* head){
    node* fast = head;
    node* slow = head;

    do{
        fast = fast->next->next;
        slow = slow->next;
    }while(fast != slow);

    while(head->next != slow->next){
        head = head->next;
        slow = slow->next;
    }
    slow->next = NULL;
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
    makeCycle(head,3);
    cout<<(checkCycle(head) ? "It is a cycle" : "It is not a cycle")<<endl;
    removeCycle(head);      //Floyd's Algorithm or Hare and Tortoise algorithm
    cout<<(checkCycle(head) ? "It is a cycle" : "It is not a cycle")<<endl;

}