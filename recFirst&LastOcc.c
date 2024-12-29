#include<stdio.h>

void occu(int arr[], int size, int i, int k, int found){
    if(i == size){
        if(found == -1){
            printf("Key not found\n");
        } else {
            printf("Last Occurrence: %d\n", found);
        }
        return;
    }
    if(arr[i] == k){
        if(found == -1){
            printf("First Occurrence: %d\n", i);
            found = i;
        }
        found = i; 
    }
    occu(arr, size, i + 1, k, found);
}


void main(){
    int arr[] = {1,2,3,4,2,5,6,2,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    occu(arr,size,0,2,-1);
}

