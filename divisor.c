#include<stdio.h>
void main(){
    int n = 27;
    int arr[n+1];

    for(int i = 0; i <= n; i++){
        arr[i] = i;
    }
    
    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == i) { 
            for (int j = i * i; j <= n; j += i) {
                if (arr[j] == j) { 
                    arr[j] = i;
                }
            }
        }
    }

    while(n != 1){
        n = n / arr[n];
        printf("%d,",n);
    }
}