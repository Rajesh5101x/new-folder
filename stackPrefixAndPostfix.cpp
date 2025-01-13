#include<iostream>
#include<cmath>
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

        int Top(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return -1;
            }
            return arr[top];
        }

        void pop(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            top--;
        }

        bool empty(){
            return top == -1;
        }

        void display(){
            if(top == -1){
                cout<<"Stack is empty"<<endl;
                return;
            }
            for(int i = 0; i <= top; i++){
                cout<<arr[i];
                if(i != top){
                    cout<<",";
                }
            }
            cout<<endl;
        }
};

int main(){
    string s = "-+7*45+20"; //prefix
    //string s = "46+2/5*7+"; //postfix
    int temp;
    stack st;
    if(isdigit(s[0])){
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
        st.push(c - '0');
    } else {
        int operand1 = st.Top();
        st.pop();
        int operand2 = st.Top();
        st.pop();

        switch (c) {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand2 - operand1); 
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand2 / operand1); 
                break;
            case '^':
                st.push(pow(operand1 , operand2));
                break;
            default:
                cout << "Invalid character encountered: " << c << endl;
                return 1;
        }
    }
        }
    }else{
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            if (isdigit(c)) {
        st.push(c - '0');
    } else {
        int operand1 = st.Top();
        st.pop();
        int operand2 = st.Top();
        st.pop();

        switch (c) {
            case '+':
                st.push(operand1 + operand2);
                break;
            case '-':
                st.push(operand1 - operand2); 
                break;
            case '*':
                st.push(operand1 * operand2);
                break;
            case '/':
                st.push(operand1 / operand2); 
                break;
            case '^':
                st.push(pow(operand1 , operand2));
                break;
            default:
                cout << "Invalid character encountered: " << c << endl;
                return 1;
        }
    }
        }
    }

    cout<<st.Top()<<endl;
}