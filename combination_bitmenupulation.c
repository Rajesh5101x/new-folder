#include<stdio.h>
#include<math.h>

int checkBit(int i, int j){
    return (i & (1 << j));
}

void main(){

    char x[] = "abc";
    int n = pow(3,2) - 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            if(checkBit(i, j)){
                printf("%c",x[j]);
            }
        }
        printf("\n");
    }
}