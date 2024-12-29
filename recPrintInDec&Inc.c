#include<stdio.h>

void pri(int n){
    printf("%d\n",n);
    if(n == 0){
        return;
    }
    pri(n-1);
    printf("%d\n",n);
}

int main(){
    int n;
    printf("Enter the number:- ");
    scanf("%d",&n);
    pri(n);
}