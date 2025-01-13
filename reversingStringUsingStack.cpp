#include<iostream>
#define n 100
using namespace std;

class stack{
    string *arr;
    int top;

    public :    
        stack(){
            arr = new string[n];
            top = -1;
        }

        void push(string val){
            if(top == n-1){
                cout<<"stack is full"<<endl;
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

        string Top(){
            if(top == -1){
                cout<<"stack is empty"<<endl;
                return "";
            }
            return arr[top];
        }

        bool empty(){
            return top == -1;
        }

};

void reverse(string s){
    string word = "";
    stack st;
    for(int i = 0; i < s.length(); i++){
        while(s[i] != ' ' && i < s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
        word = "";
    }

    while(!st.empty()){
        cout<<st.Top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main(){
    string s = "Hey! my name is Rajesh Rana.";
    reverse(s);

    return 0;
}