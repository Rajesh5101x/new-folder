#include<stdio.h>


void rev(char x[], int n){
    if(x[n] == '\0'){
        return;
    }
    rev(x,n+1);
    printf("%c",x[n]);
}


void main(){
    char x[] = "rajesh";
    int size = sizeof(x)/sizeof(x[0]);
    rev(x,0);
}