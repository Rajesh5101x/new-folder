#include<iostream>
using namespace std;

void consecutive(int arr[],int size, int k){
    int count = 0, j = 0, ans = 0;

    for(int i = 0; i < size; i++){
        if(arr[i] == 0){
            count++;
        }
        while (count > k){
            if(arr[j] == 0){
                count--;
            }
            j++;
        }
        ans = max(ans,i-j+1);
    }
    cout<<ans<<endl;
}

int main(){
    int arr1[] = {1,1,1,0,0,0,1,1,1,1,0};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int k1 = 2;
    consecutive(arr1,size1,k1);

    int arr2[] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int k2 = 3;
    consecutive(arr2,size2,k2);
    
}