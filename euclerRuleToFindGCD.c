#include<stdio.h>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    gcd(b,a%b);
}

void main(){
    printf("%d",gcd(42,24));
}
