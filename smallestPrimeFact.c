#include<stdio.h>

int main(){
    int n;
    printf("Enter the number:- ");
    scanf("%d",&n);
    int arr[n+1];

    for(int i = 2; i <= n; i++){
        arr[i] = i;
    }

    for(int i = 2; i <= n; i++){
        if(arr[i] == i){
            for(int j = i*i; j <= n; j += i){
                if(arr[j] == j){
                    arr[j] = i;
                }
            }
        }
    }

    printf("Prime factors of %d: ", n);
    while(n != 1){
        
        printf("%d x ",arr[n]);
        n = n / arr[n];
    }

    return 0;
}