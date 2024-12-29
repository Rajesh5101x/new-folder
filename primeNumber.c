//Sieve of Eratosthenes

#include<stdio.h>
#include<math.h>

void main(){
    int n = 50, i;
    int arr[n+1];

    for(i = 0; i < n; i++){
        arr[i] = i;
    }

    for(i = 2; i*i <= n; i++){
        if(arr[i] != 0){
            for(int j = i*i; j <= n; j+=i){
                arr[j] = 0;
            }   
        }
    }
    for(i = 2; i < n; i++){
        if(arr[i]){
            printf("%d,",arr[i]);
        }
    }
}