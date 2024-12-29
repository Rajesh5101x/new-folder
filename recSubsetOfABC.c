#include<stdio.h>

void reco(char arr[], int i, char x[], int j){
    if(arr[i] == '\0') {
        x[j] = '\0';
        printf("%s\n",x);
        return;
    }
    reco(arr,i+1,x,j);
    
    x[j] = arr[i];
    reco(arr,i+1,x,j+1);

    int asciiValue = arr[i];
    char buffer[4];
    int k = 0;
    snprintf(buffer,sizeof(buffer),"%d",asciiValue);
    while (buffer[k] != '\0') {
        x[j++] = buffer[k++];
    }
    reco(arr, i + 1, x, j);
    
}

void main(){
    char arr[] = "AB";
    char x[100];
    reco(arr,0,x,0);
}