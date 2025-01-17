#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> arr = {2,1,5,6,2,3};
    stack<int> st;
    int size = arr.size(), i = 0, ans = 0;
    arr.push_back(0);

    while(i < size){
        while(!st.empty() && arr[st.top()] < arr[i]){
            int t = st.top();
            int h = arr[t];
            st.pop();

            if(!st.empty()){
                ans = max(ans, h * i);
            }else{
                int l = i - st.top() - 1;
                ans = max(ans, h * l);
            }
        }
        st.push(i);
        i++;
    }

    printf("%d",ans);
}