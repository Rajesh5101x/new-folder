#include<stdio.h>

void main(){
    int n = 1000;
    int c1 = n/5, c2 = n/7, c3 = n/(5*7);
    printf("Total number are :- %d",((c1+c2)-c3));
}