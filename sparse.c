#include <stdio.h>

void creation(int arr[][6], int m1, int n1);
void display(int arr[][6], int m1, int n1);
void sparse(int arr[][6], int m1, int n1);
void alternate(int arr[][6], int m1, int n1, int spar[][3], int nz);

int main() {
    int m1 = 5, n1 = 6;
    int arr[m1][n1];
    creation(arr, m1, n1);
    display(arr, m1, n1);
    sparse(arr, m1, n1);
    return 0;
}

void creation(int arr[][6], int m1, int n1) {
    for (int i = 0; i < m1; i++) {
        printf("Enter %d row values:\n", i + 1);
        for (int j = 0; j < n1; j++) {
            printf("    Enter value for row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");
}

void display(int arr[][6], int m1, int n1) {
    printf("The elements in the array are:\n");
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d", arr[i][j]);
            if (j != n1 - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void sparse(int arr[][6], int m1, int n1) {
    int nz = 0;
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (arr[i][j] != 0) {
                nz++;
            }
        }
    }

    if (((nz * 3) + 3) > (m1 * n1)) {
        printf("It is not a sparse matrix.\n");
    } else {
        printf("It is a sparse matrix.\n");
        int spar[nz + 1][3];
        alternate(arr, m1, n1, spar, nz + 1);

        // Display the sparse matrix representation
        printf("Sparse matrix representation:\n");
        for (int i = 0; i < nz + 1; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", spar[i][j]);
            }
            printf("\n");
        }
    }
}

void alternate(int arr[][6], int m1, int n1, int spar[][3], int nz) {
    int k = 0;
    spar[k][0] = m1;
    spar[k][1] = n1;
    spar[k++][2] = nz - 1;

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            if (arr[i][j] != 0) {
                spar[k][0] = i;
                spar[k][1] = j;
                spar[k++][2] = arr[i][j];
            }
        }
    }
}