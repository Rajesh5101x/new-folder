#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reco(int arr[], int size, int i){
    if(i == size){
        for(int k = 0; k < 3; k++){
            printf("%d",arr[k]);
        }
        printf("\n");
        return;
    }
    for(int q = i; q < size; q++){
        swap(&arr[i],&arr[q]);
        reco(arr, size, i + 1);
        swap(&arr[i],&arr[q]);
    }
    
}

void main(){
    int arr[3] = {1,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    reco(arr,size,0);
}