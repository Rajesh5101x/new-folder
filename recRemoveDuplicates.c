#include<stdio.h>

void reco(char arr[], int i, char x[], int j){
    if (arr[i] == '\0'){
        x[j] = '\0';
        printf("%s",x);
        return;
    }
    if(arr[i] != arr[i+1]){
        x[j] = arr[i];
        j++;
    }
    reco(arr,i+1,x,j);
}

void main(){
    char arr[] = "aaaabbbbcccccddddddddddd";
    char x[100];
    reco(arr,0,x,0);
}


/* void reco(char arr[], int i){
    if (arr[i] == '\0'){
        return;
    }
    if(arr[i] != arr[i+1]){
        printf("%c",arr[i]);
    }
    reco(arr,i+1);
}

void main(){
    char arr[] = "aaaabbbbcccccddddddeddddd";
    reco(arr,0);
} */