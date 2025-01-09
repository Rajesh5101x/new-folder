#include<stdio.h>
#include<math.h>

void main(){
    int n = 110100100;
    int x = 0, i = 0;
    while(n != 0){
        x = x + ((n % 10)*pow(2,i));
        n = n / 10;
        i++;
    }
    printf("%d",x);
}