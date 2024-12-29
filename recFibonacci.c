#include<stdio.h>

void fab(int a, int b, int c){
    if (c == 5){
        return;
    }
    printf(",%d",a+b);
    fab(b,a+b,c+1);
}

int main(){
    printf("%d,%d",0,1);
    fab(0,1,2);
    return 0;
}