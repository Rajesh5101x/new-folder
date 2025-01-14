#include<iostream>
using namespace std;
#define n 100

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
                cout<<"Stack is full"<<endl;
                return;
            }
            arr[++top] = val;
        }

        void pop(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            top--;
        }

        void Top(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            cout<<arr[top]<<endl;
        }

        bool empty(){
            return top == -1;
        }

        void displayFront(){
            if(top == -1){
                cout<<"stack is empty\n";
                return;
            }
            cout<<*(arr + 0)<<endl;
        }
};

int main(){
    stack st;
    cout<<((st.empty()) ? "Stack is empty" : "Stack is not empty")<<endl;
    st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.Top();
    st.pop();
    st.Top();
    st.displayFront();

    return 0;
}