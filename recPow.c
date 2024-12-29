#include<stdio.h>

int powe(int n, int p){
    if(p == 0){
        return 1;
    }
    
    return n * powe(n,p-1);
}


void main(){
    int n, p;
    printf("Enter the number and power:- ");
    scanf("%d %d",&n,&p);
    printf("%d",powe(n,p));
}