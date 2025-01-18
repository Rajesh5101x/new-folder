#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> a = {12,3,7,1,6,9};
    int target = 25;
    bool found = false;
    sort(a.begin(),a.end());

    for(int i = 0; i < a.size(); i++){
        int lb = i + 1, ub = a.size() - 1;

        while(lb < ub){
            int current = a[i] + a[lb] + a[ub];
            if(current == target){
                cout<<a[i]<<","<<a[lb]<<","<<a[ub]<<endl;
                found = true;
                break;
            }else if(current > target){
                ub--;
            }else{
                lb++;
            }
        }
        if(found){
            break;
        }
    }
    
}