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
                cout<<"Stack is full"<<endl;
                return;
            }
            arr[++top] = val;
        }

        void pop(){
            if(top == -1){
                cout<<"stack is empty"<<endl;
                return;
            }
            top--;
        }

        int Top(){
            if(top == -1){
                cout<<"stack is empty"<<endl;
                return -1;
            }
            return arr[top];
        }

        int empty(){
            return top == -1;
        }

        void display() {
            if (empty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }

        int length() {
            return top + 1;
        }

        void insertAtBottom(int val){
            if(empty()){
                push(val);
                return;
            }

            int temp = Top();
            pop();
            insertAtBottom(val);
            push(temp);
        }

        void reverse(){
            if(empty()){
                return;
            }

            int temp = Top();
            pop();            
            reverse();
            insertAtBottom(temp);
        }
};

int main(){
    stack st;
    st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout<<st.Top()<<endl;
    st.display();
    st.reverse();
    st.display();

    return 0;
}