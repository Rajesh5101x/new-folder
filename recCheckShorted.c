#include<stdio.h>

int shorted(int arr[],int i, int n){
    if(i == n-1){
        return 1;
    }

    return (arr[i]<=arr[i+1] && shorted(arr,i+1,n));
}


int main(){
    int n[] = {1,2,3,4,5,7};
    int size = sizeof(n)/sizeof(n[0]);
    printf("%d",shorted(n,0,size));

    return 0;
}