#include<stdio.h>

int checkBit(int n, int pos){
    return(n & (1 << pos));
}

void reco(int arr[], int size){
    int xorSum = 0, position = 0, i = 0, firstNum, secondNum;
    for(i = 0; i < size; i++){
        xorSum = xorSum ^ arr[i];
    }
    
    while(!position){
        if(checkBit(xorSum,i)){
            position = i;
        }
        i++;
    }

    for(i = 0; i < size; i++){
        if(checkBit(arr[i],position)){
            firstNum = arr[i];
            break;
        }
    }
    secondNum = xorSum ^ firstNum;
    printf("%d,%d",firstNum,secondNum);
}

void main(){
    int arr[] = {5,6,3,4,3,4,6,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    reco(arr,size);
}