#include <stdio.h>

void main() {
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }

    int countArr[maxVal + 1];
    for (int i = 0; i <= maxVal; i++) countArr[i] = 0;

    for (int i = 0; i < n; i++) {
        countArr[arr[i]]++;
    }

    int position[maxVal + 1];
    position[0] = countArr[0];
    for (int i = 1; i <= maxVal; i++) {
        position[i] = position[i - 1] + countArr[i];
    }

    int newArr[n];
    for(int i = n - 1; i >= 0; i--) {
        newArr[--position[arr[i]]] = arr[i];
    }
    

    for (int i = 0; i < n; i++) {
        printf("%d", newArr[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");
}
