#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int insert(int **prt, int n){
    int n1;
    printf("Enter the number of new data to be entered : ");
    scanf("%d",&n1);
    n1 += n;

    *prt = (int *)realloc(*prt, n1*sizeof(int));
    printf("Enter the new elements : \n");
    for(int i = n; i < n1; i++){
        scanf("%d",(*prt + i));
    }
    return n1;
}

void display(int *prt, int n){
    printf("Elements are :- ");
    for(int i = 0; i < n; i++){
        printf("%d",*(prt + i));
        if(i < n-1){
            printf(", ");
        }
    }
    printf("\n");
}

int main(){
    char flag[4];
    int n;
    printf("Enter the number of data to be entered : ");
    scanf("%d",&n);
    int *prt = (int *)malloc(n*sizeof(int));
    printf("Enter the elements : \n");
    for(int i = 0; i < n; i++){
        scanf("%d",(prt + i));
    }
    display(prt,n);
    printf("Do you want to add more elements : \n Enter in yes or no :- ");
    scanf(" %s",flag);
    if(strcmp(flag, "yes") == 0){
        n = insert(&prt,n);
        display(prt,n);
    }
    printf("Thank you!");

    free(prt); 
    return 0;
}