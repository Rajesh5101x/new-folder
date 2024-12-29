#include<stdio.h>
#include<string.h>

void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reco(char arr[], int i, int size){
    if(i == size){
        printf("%s\n",arr);
        return;
    }
    for(int k = i; k < size; k++){
        swap(&arr[i],&arr[k]);
        reco(arr,i + 1, size);
        swap(&arr[i],&arr[k]);
    }
}


void main() {
    char arr[] = "abc"; // Automatically includes null terminator
    int size = strlen(arr);
    reco(arr, 0, size);
}

