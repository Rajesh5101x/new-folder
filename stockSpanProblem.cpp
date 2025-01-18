#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    vector<int> arr = {100,80,60,70,60,75,85};
    vector<int> ans;
    stack<pair<int,int>> s;

    for(auto price : arr){
        int days = 1;
        while(!s.empty() && s.top().first <= price){
            days += s.top().second;
            s.pop();
        }
        s.push(make_pair(price,days));
        ans.push_back(days);

    }

    for(auto span : ans){
        cout<<span<<" ";
    }
    cout<<endl;
}