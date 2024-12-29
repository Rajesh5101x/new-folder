#include<stdio.h>

int max(int a, int b){
    return ((a > b)? a : b);
}

int reco(int wt[], int value[], int n, int w){
    if(n == 0 || w == 0){
        return 0;
    }

    if(wt[n - 1] > w){
        return reco(wt, value, n - 1, w);
    }

    max(reco(wt, value, n-1, w - wt[n - 1]) + value[n - 1], reco(wt, value, n - 1, w));
}

void main(){
    int wt[] = {10,20,30};
    int value[] = {100,50,150};
    printf("The max value is :- %d", reco(wt, value, 3, 50));
}