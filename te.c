#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int temp;
    vector<int> v;
    for(int i = 0; i < 6; i++){
        v.push_back(i);
    }
    
    // v2.push_back(make_pair("rajesh", 19));

    vector<int>::iterator it;

    for(it = v.begin(); it != v.end(); it++){
        cout<<*it;
        if (it != v.end() - 1) {
            cout << ",";
        }
    }

    cout<<endl;

    bool first = false; 
    for(auto i:v){
        if (first) {
            cout << ","; 
        }
        cout<<i;
        first = true;
    }
    return 0;
}