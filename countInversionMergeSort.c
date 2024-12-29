#include<stdio.h>

int sort(int arr[], int l, int mid, int r){
    int inv = 0;

    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1], b[n2];
    for(int i = 0; i < n1; i++){
        a[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++){
        b[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            k++; i++;
        }else{
            arr[k] = b[j];
            inv += n1 - i;
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
    return inv;
}

int reco(int arr[], int l, int r){
    int inv = 0;
    if(l < r){
        int mid = (l + r) / 2;
        inv += reco(arr, l, mid);
        inv += reco(arr, mid + 1, r);
        inv += sort(arr, l, mid, r);
    }
    return inv;
}

void main(){
    int arr[] = {3,5,6,9,1,2,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Total number of inversion are :- %d",reco(arr, 0, n - 1));
}



/* void main(){
    int arr[] = {3,5,6,9,1,2,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int inv = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((arr[i] > arr[j]) && (i < j)){
                printf("(%d,%d)",arr[i],arr[j]);
                inv++;
                if(j < n - 1){
                    printf(",");
                }
            }
        }
    }
    printf("\nTotal number of inversion are :- %d",inv);
} */