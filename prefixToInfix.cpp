#include<iostream>
#include<string>
#include<stack>
using namespace std;

string convertPrefix(string s){
    stack<string> st;
    for(int i = (s.length()-1); i >= 0; i--){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            string operand(1, s[i]);
            st.push(operand);
        }else if(isdigit(s[i])){
            string operand(1, s[i]);
            st.push(operand);
        }else{
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string expr = "(" + op1 + s[i] + op2 + ")";
            st.push(expr);
        }
    }
    return st.top();
}

string convertPostfix(string s){
    stack<string> st;
    for(int i = 0; i < (s.length()); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            string operand(1,s[i]);
            st.push(operand);
        }else if(isdigit(s[i])){
            string operand(1,s[i]);
            st.push(operand);
        }else{
            string s1 = st.top();
            st.pop();
            string s2 = st.top();
            st.pop();
            string temp = "(" + s2 + s[i] + s1 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    cout<<"Prefix convertion :-"<<endl;
    cout<<convertPrefix("*-a/bc-/akl")<<endl;
    cout<<"postfix convertion :- "<<endl;
    cout<<convertPostfix("123/-12/3-*")<<endl;

    return 0;
}