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

        void Top(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            cout<<arr[top]<<endl;
        }

        void pop(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            top--;
        }

        int empty(){
            return top == -1;
        }
};

int main(){
    stack st;
    cout<<st.empty()<<endl;
    st.push(1);
    st.push(2);
    st.Top();
    st.pop();
    st.Top();
}