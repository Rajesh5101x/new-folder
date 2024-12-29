#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool myCompare(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}

int main(){
    int arr[] = {10,16,7,14,5,3,12,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int,int>> v;

    for(int i = 0; i < n; i++){
        v.push_back(make_pair(arr[i],i));
    }

    sort(v.begin(),v.end(),myCompare);

    for(int i = 0; i < n; i++){
        arr[v[i].second] = i;
    }

    bool flag = false;

    for(int i = 0; i < n; i++){
        if(flag){
            cout<<",";
        }
        cout<<arr[i];
        flag = true;
    }
    cout<<endl;
    return 0;
}