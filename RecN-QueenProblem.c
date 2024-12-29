#include<stdio.h>

int arr[4][4] = {0};

int isSafe(int i, int j, int n) {
    // Check column
    for (int k = 0; k < i; k++) {
        if (arr[k][j]) {
            return 0;
        }
    }

    // Check left diagonal
    int k = i - 1, q = j - 1;
    while (k >= 0 && q >= 0) {
        if (arr[k][q]) {
            return 0;
        }
        k--;
        q--;
    }

    // Check right diagonal
    k = i - 1;
    int p = j + 1;
    while (k >= 0 && p < n) {
        if (arr[k][p]) {
            return 0;
        }
        k--;
        p++;
    }

    return 1;
}

void reco(int i, int count, int n) {
    if (count == n) {
        // Print solution
        for (int g = 0; g < n; g++) {
            for (int h = 0; h < n; h++) printf("%d ", arr[g][h]);
            printf("\n");
        }
        printf("\n");
        return;
    }

    if (i >= n) return;

    for (int j = 0; j < n; j++) {
        if (isSafe(i, j, n)) {
            arr[i][j] = 1;          
            reco(i + 1, count + 1, n);
            arr[i][j] = 0;           
        }
    }
}

int main() {
    reco(0, 0, 4);
    return 0;
}
