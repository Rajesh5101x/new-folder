#include<iostream>
#include<string>
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
            if(top == n-1){
                cout<<"Stack is full";
                return;
            }
            arr[++top] = val;
        }

        char Top(){
            if(top == -1){
                return '\0';
            }
            return arr[top];
        }

        bool empty(){
            return top == -1;
        }

        void pop(){
            if(top == -1){
                cout<<"Stack is empty";
                return;
            }
            top--;
        }
};

int priority(char c){
    if(c == '^'){
        return 3;
    }

    if(c == '*' || c == '/'){
        return 2;
    }

    if(c == '+' || c == '-'){
        return 1;
    }

    return -1;
}

string converter(string s) {
    stack st;
    string rec;

    for (int i = 0; i < s.length(); i++) {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            rec += s[i];
        }else if(isdigit(s[i])){
            rec += s[i];
        }else if (s[i] == '(') {
            st.push(s[i]);
        }else if (s[i] == ')') {
            while (!st.empty() && st.Top() != '(') {
                rec += st.Top();
                st.pop();
            }
            if (!st.empty() && st.Top() == '(') {
                st.pop(); 
            }
        }else {
            while (!st.empty() && priority(st.Top()) >= priority(s[i])) {
                rec += st.Top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()) {
        rec += st.Top();
        st.pop();
    }

    return rec; 
}

int main(){
    cout<<"PostFix Expression :-"<<endl;
    string s = "(a-b/c)*(a/k-l)";
    cout<<converter(s)<<endl;
    cout<<converter("(1-2/3)*(1/2-3)")<<endl;
}