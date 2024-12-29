#include<string.h>
#include<stdio.h>

void rep(char arr[], int i){
    if(arr[i] == '\0'){
        return;
    }
    if(arr[i] == 'p' && arr[i+1] == 'i'){
        printf("3.14");
        rep(arr,i+2);
    }else{
        printf("%c",arr[i]);
        rep(arr,i+1);
    }
}

void main(){
    char arr[] = "pippxxppiixipi";
    rep(arr,0);
}

/* void rep(char arr[],int i, char *y, int j){
    if(arr[i] == '\0'){
        y[j] = '\0';
        return;
    }
    if(arr[i] == 'p' && arr[i+1] == 'i'){
        y[j] = '3';
        y[j + 1] = '.';
        y[j + 2] = '1';
        y[j + 3] = '4';
        rep(arr,i+2,y,j+4);
    }else{
        y[j] = arr[i];
        rep(arr,i+1,y,j+1);
    }
}

void main(){
    char arr[] = "pippxxppiixipi";
    char x[100];
    char *prt = x;
    rep(arr,0,prt,0);
    printf("%s",x);
} */