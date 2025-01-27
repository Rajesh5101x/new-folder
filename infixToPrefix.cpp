#include<iostream>
#include<stack>
#include<string>
#include <algorithm> 
using namespace std;

int precidency(char s){
    if(s == '^'){
        return 3;
    }

    if(s == '*' || s == '/'){
        return 2;
    }

    if(s == '+' || s == '-'){
        return 1;
    }
    return -1;
}

string converter(string s){
    stack<char> st;
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
            while(!st.empty() && precidency(st.top()) >= precidency(s[i])){
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
    reverse(rec.begin(),rec.end());
    return rec;
}

int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout<<converter(s)<<endl;
    cout<<converter("(1-2/3)*(1/2-3)")<<endl;
}