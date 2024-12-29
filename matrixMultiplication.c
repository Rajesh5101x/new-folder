#include<stdio.h>
void main(){
    int arr1[2][3] = {{1,2,3},{4,5,6}};
    int arr2[3][3] = {{1,2,3},{4,5,6},{2,3,1}};
    int arr[2][3] = {};
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            int sum = 0;
            for(int k = 0; k < 3; k++){
               sum += (arr1[i][k] * arr2[k][j]); 
            }
            arr[i][j] = sum;
        }
    }
    for(int i = 0; i < 2; i++){
        printf("[");
        for(int j = 0; j < 3; j++){
            printf("%d,",arr[i][j]);
        }
        printf("]\n");
    }
    
}