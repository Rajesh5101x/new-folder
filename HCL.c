#include<stdio.h>
int main(){
    int a, b, temp;
    printf("Enter two number:- ");
    scanf("%d %d",&a,&b);

    while(b != 0){
        temp = b;
        b = a % b;
        a = temp;
    }

    printf("The HCL is a :- %d",a);
}