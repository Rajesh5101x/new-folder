#include<iostream>
#define n 100
using namespace std;

class stack{
    char *arr;
    int top;

    public :    
        stack(){
            arr = new char[n];
            top = -1;
        }

        void push(char val){
            if(top == n - 1){
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

        char Top(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return '\0';
            }
            return arr[top];
        }

        bool empty(){
            return top == -1;
        }
};


bool check(string s){
    stack st;
    for(char c : s){
        if(c == ')'){
            bool hasOperator = false;

            while(!st.empty() && st.Top() != '('){
                if (st.Top() == '+' || st.Top() == '-' || st.Top() == '*' || st.Top() == '/') {
                    hasOperator = true;
                }
                st.pop();
            }

            if (!st.empty() && st.Top() == '(') {
                st.pop();
            }

            if(!hasOperator){
                return true;
            }
        }else{
            st.push(c);
        }
    }
    return false;
}

int main(){
    string s = "(a * (a + b))";
    cout<<check(s)<<endl;
    
}