#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main(){
    deque<int> dq;
    int arr[] = {1,3,-1,-3,5,3,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    vector<int> rec;

    for(int i = 0; i < size; i++){
        if(!dq.empty() && dq.front() == i - k){
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);

        if(i >= k-1){
            rec.push_back(arr[dq.front()]);
        }
    }

    for(int i = 0; i < rec.size() ; i++){
        cout<<rec[i];
        if(i != rec.size()-1){
            cout<<",";
        }
    }
    cout<<endl;
}