#include<stdio.h>

int reco(int i, int j, int a, int b){
    if(i == a-1 || j == b-1){
        return 1;
    }
    int count = 0;
    count += reco(i+1, j, a, b);
    count += reco(i, j + 1, a, b);
    return count;
}

void main(){
    int a = 9;
    int b = 9;
    printf("Total ways are :- %d",reco(0,0,a,b));
}