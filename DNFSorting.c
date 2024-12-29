#include<stdio.h>

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void main(){
    int arr[] = {1,1,2,0,0,1,2,2,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0, mid = 0, high = n - 1;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr,low,mid);
            low++; mid++;
        }

        if(arr[mid] == 1){
            mid++;
        }

        if(arr[mid] == 2){
            swap(arr,mid,high);
            high--;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d",arr[i]);
        if(i < n - 1){
            printf(",");
        }
    }
}