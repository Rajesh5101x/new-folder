#include<stdio.h>

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int l, int r){
    int k = arr[r];
    int i = l - 1;

    for(int j = l; j < r; j++){
        if(arr[j] < k){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i + 1;
}

void reco(int arr[], int l, int r){
    if(l < r){
        int pi = partition(arr,l,r);
        reco(arr,l,pi-1);
        reco(arr,pi+1,r);
    }
}

void main(){
    int arr[] = {5,2,4,6,3,1,9,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    reco(arr,0,n - 1);
    for(int i = 0; i < n; i++){
        printf("%d",arr[i]);
        if(i < n - 1){
            printf(",");
        }
    }
}