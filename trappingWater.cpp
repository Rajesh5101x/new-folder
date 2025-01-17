#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int l = 0, r = size - 1;
    int lMax = 0, rMax = 0; 
    int total = 0;           

    while (l <= r) {
        if (arr[l] <= arr[r]) {
            if (arr[l] >= lMax) {
                lMax = arr[l]; 
            } else {
                total += lMax - arr[l]; 
            }
            l++;
        } else {
            if (arr[r] >= rMax) {
                rMax = arr[r]; 
            } else {
                total += rMax - arr[r]; 
            }
            r--;
        }
    }

    cout << "Total trapped water: " << total << endl;
    return 0;
}
