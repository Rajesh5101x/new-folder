#include<stdio.h>
#include<stdlib.h>

void main(){
    int *p, i , n , sum = 0;
    printf("Enter the total number of number to be entered : ");
    scanf("%d",&n);
    p = (int *)calloc(n , sizeof(int));

    printf("Enter the elements");
    for(int i = 0; i < n; i++){
        scanf("%d",(p + i));
        sum += *(p + i);
    }
    printf("Sum = %d",sum);
    free(p);
}