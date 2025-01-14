#include<iostream>
using namespace std;
#define n 100

class queue{
    int *arr;
    int front;
    int back;

    public :
        queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }

        void enqueue(int val){
            if(back == n-1){
                cout<<"Stack is full\n";
                return;
            }
            arr[++back] = val;
            if(front == -1){
                front++;
            }
        }

        void dequeue(){
            if(front == n-1 || front > back){
                cout<<"satck is empty\n";
                return;
            }
            front++;
        }

        int peek(){
            if(front == n-1 || front > back){
                cout<<"satck is empty\n";
                return -1;
            }
            return arr[front];
        }

        bool empty() {
            return (front == -1 || front > back);
        }

        int size() {
            if (empty()) return 0;
            return back - front + 1;
        }
};

void push(queue &qe, int val){
    qe.enqueue(val);
}

void pop(queue &qe) {
    if (qe.empty()) {
        cout << "Stack is empty\n";
        return;
    }

    queue temp;
    while (qe.size() > 1) {
        temp.enqueue(qe.peek());
        qe.dequeue();
    }
    qe.dequeue();

    while (!temp.empty()) {
        qe.enqueue(temp.peek());
        temp.dequeue();
    }
}

void top(queue &qe){
    if (qe.empty()) {
        cout << "Stack is empty\n";
        return;
    }

    queue temp;
    while (qe.size() > 1) {
        temp.enqueue(qe.peek());
        qe.dequeue();
    }
    cout<<qe.peek()<<endl;
    temp.enqueue(qe.peek());
    qe.dequeue();

    while (!temp.empty()) {
        qe.enqueue(temp.peek());
        temp.dequeue();
    }   
}

int main(){
    queue qe;
    push(qe,1);
    push(qe,2);
    push(qe,3);
    push(qe,4);
    top(qe);
    pop(qe);
    top(qe);

    return 0;
}