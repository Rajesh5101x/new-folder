#include<stdio.h>

void main(){
    int arr[] = {5,2,4,6,3,1,9,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 1; i < n; i++){
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    for(int i = 0; i < n; i++){
        printf("%d",arr[i]);
        if(i < n - 1){
            printf(",");
        }
    }
}

