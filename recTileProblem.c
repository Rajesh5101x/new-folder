#include<stdio.h>

int reco(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return reco(n-1) + reco(n-2);
}

void main(){
    printf("Total possible ways are :- %d",reco(4));
}