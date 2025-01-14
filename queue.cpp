#include<iostream>
#define n 100
using namespace std;

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
                cout<<"Queue is full\n";
                return;
            }
            arr[++back] = val;
            if(front == -1){
               front = 0; 
            }
        }

        void dequeue(){
            if(front == -1 || front > back){
                cout<<"Queue is empty\n";
                return;
            }
            front++;
        }

        void peek(){
            if(front == -1){
                cout<<"Queue is empty"<<endl;
                return;
            }
            cout<<arr[front]<<endl;
        }

        int empty(){
            return(front == -1 || front > back);
        }
};

int main(){
    queue qe;
    qe.enqueue(1);
    qe.enqueue(2);
    qe.enqueue(3);
    qe.enqueue(4);
    qe.enqueue(5);
    qe.enqueue(6);
    qe.peek();
    qe.dequeue();
    qe.peek();
    cout<<qe.empty()<<endl;
    
    return 0;
}