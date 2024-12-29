#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter the number:- ");
    scanf("%d",&a);
    printf("Enter the two divisible:- ");
    scanf("%d %d",&b,&c);

    int temp1 = a/b;
    int temp2 = a/c;
    int temp3 = a/(b*c);

    printf("The total number of divisor are:- %d",(temp1 + temp2) - temp3);
    return 0;
}