#include<stdio.h>

void main(){
    int x = 4;
    int n = 1;

    for(int i = 1; i <= x; i++){
        for(int j = 0; j <= (x-i); j++){
            printf("  ");
        }
        for(int k = 0; k < i; k++){
            printf("%d ",n++);
        }
        while((n-1) > 1){
            printf("%d ",n-2);
            n--;
        }
        printf("\n");
        n = 1;
    }
}