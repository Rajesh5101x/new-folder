#include<stdio.h>

void reco(char arr[], int i, char x[], int j){
    static int count = 0;
    if(arr[i] == '\0'){
        for(int k = 0; k < count; k++){
            x[j++] = 'x';
        }
        x[j] = '\0';
        printf("%s",x);
        return;
    }
    if(arr[i] != 'x'){
        x[j++] = arr[i];
    }else{
        count++;
    }
    reco(arr,i+1,x,j);
}

void main(){
    char arr[] = "axxbdxcefxhix";
    char x[100];
    reco(arr,0,x,0);
}