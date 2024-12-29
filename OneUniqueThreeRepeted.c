#include<stdio.h>

int setBit(int x, int pos){
    return (x | (1 << pos));
}

int checkBit(int x, int pos){
    return(x & (1 << pos));
}

void find(int arr[], int size){
    int x[8] = {0};
    int number = 0;
    for(int i = 0; i < 8; i++){
        int count = 0;
        for(int j = 0; j < size; j++){
            if(checkBit(arr[j],i)){
                count++;
            }
        }
        x[i] = count;
    }

    for(int i = 0; i < 8; i++){
        if(x[i] % 3 != 0){
            number = setBit(number,i);
        }
    }
    printf("%d",number);
}

int main(){
    int arr[] = {3,3,3,1,1,1,4,5,5,5,8,8,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    find(arr,size);

    return 0;
}