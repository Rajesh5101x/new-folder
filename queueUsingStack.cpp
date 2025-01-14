#include<iostream>
#define n 100
using namespace std;

class stack{
    int *arr;
    int top;

    public :
        stack(){
            arr = new int[n];
            top = -1;
        }

        void push(int val){
            if(top == n-1){
                cout<<"Stack is full\n";
                return;
            }
            arr[++top] = val;
        }

        void pop(){
            if(top == -1){
                cout<<"stack is empty\n";
                return;
            }
            top--;
        }

        int Top(){
            if (top == -1) {
                cout << "Stack is empty\n";
                return -1; 
            }
            return arr[top];
        }

        int empty(){
            return top == -1;
        }

        void display() {
            if (top == -1) {
                cout << "Stack is empty\n";
                return;
            }
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

void enqueue(stack** st, int val){
    (*st)->push(val);
}

void dequeue(stack** st){
    if ((*st)->empty()) {
        cout << "Queue is empty\n";
        return;
    }

    stack temp;
    while(!(*st)->empty()){
        temp.push((*st)->Top());
        (*st)->pop();
    }
    temp.pop();
    while(!temp.empty()){
        (*st)->push(temp.Top());
        temp.pop();
    }
}

int main(){
    stack* st = new stack();
    enqueue(&st,1);
    enqueue(&st,2);
    enqueue(&st,3);
    enqueue(&st,4);
    st->display();
    
    dequeue(&st);
    st->display();

    delete st;
    return 0;
}