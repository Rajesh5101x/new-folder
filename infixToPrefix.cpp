#include<iostream>
#include<string>
#define n 100
using namespace std;

class stack{
    char *arr;
    int Top;

    public : 
        stack(){
            arr = new char[n];
            Top = -1;
        }

        void push(char val){
            if(Top == n-1){
                cout<<"Stack is full";
                return;
            }
            arr[++Top] = val;
        }

        char top(){
            if(Top == -1){
                return '\0';
            }
            return arr[Top];
        }

        bool empty(){
            return Top == -1;
        }

        void pop(){
            if(Top == -1){
                cout<<"Stack is empty";
                return;
            }
            Top--;
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

string converter(string s){
    stack st;
    string rec;
    for(int i = (s.length()-1); i >= 0; i--){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            rec += s[i];
        }else if(isdigit(s[i])){
            rec += s[i];
        }else if(s[i] == ')'){
            st.push(s[i]);
        }else if(s[i] == '('){
            while(!st.empty() && st.top() != ')'){
                rec += st.top();
                st.pop();
            }
            if(!st.empty() && st.top() == ')'){
                st.pop();
            }
        }else{
            while(!st.empty() && priority(st.top()) > priority(s[i])){
                rec += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        rec += st.top();
        st.pop();
    }
    return rec;
}

int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout<<converter(s)<<endl;
    cout<<converter("(1-2/3)*(1/2-3)")<<endl;
}