#include<stdio.h>

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void main(){
    int arr[] = {1,3,4,7,5,6,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 1; i < n; i+=2){
        if(arr[i] > arr[i - 1]){
            swap(arr, i, i - 1);
        }

        if(arr[i] > arr[i + 1] && i <= n - 2){
            swap(arr, i, i + 1);
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d",arr[i]);
        if(i < n - 1){
            printf(",");
        }
    }
}