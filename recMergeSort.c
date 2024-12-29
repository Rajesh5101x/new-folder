#include<stdio.h>

void merge(int arr[], int l, int mid, int r){ //0 1 3
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    for(int i = 0; i < n1; i++){
        a[i] = arr[l + i];
    }

    for(int j = 0; j < n2; j++){
        b[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            i++; k++;
        }else{
            arr[k] = b[j];
            k++; j++;
        }
    }

    while(i < n1){
        arr[k] = a[i];
        k++; i++;
    }

    while(j < n2){
        arr[k] = b[j];
        k++; j++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int mid = (l + r)/2;

        mergeSort(arr,l,mid);
        mergeSort(arr,mid + 1, r);

        merge(arr, l, mid, r);
    }
}

void main(){
    int arr[] = {5,2,4,6,3,1,9,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++){
        printf("%d,",arr[i]);
    }
}