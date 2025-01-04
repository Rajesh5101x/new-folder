#include<stdio.h>
void main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 4;

    int l = 0, r = size-1;
    while(l <= r){
        int m = (l + r) / 2;

        if(arr[m] == key){
            printf("Key is found at index %d",m);
            break;
        }else if(arr[m] > key){
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    if(l > r){
        printf("Key not found in the array.");
    }
}