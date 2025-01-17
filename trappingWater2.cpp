#include<iostream>
#include<stack>
using namespace std;

int main(){
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    stack<int> st;
    int total = 0;
    
    for(int i = 0; i < size; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            int top = st.top();
            st.pop();

            if(st.empty()){
                break;
            }else{
                int l = i - st.top() - 1;
                total += (min(arr[i],arr[st.top()]) - arr[top]) * l;
            }
        }
        st.push(i);
    }
    cout<<total<<endl;
}