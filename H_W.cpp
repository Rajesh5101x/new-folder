#include <iostream>

using namespace std;

int main() {
    int arr[] = {10, 7, 45, 67, 801, 1048, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 2) {
        cout << n;
        return 0;
    }

    int max_length = 1;
    int current_length = 2;
    int cd = arr[1] - arr[0];

    for (int i = 1; i < n - 1; ++i) {
        if ((arr[i + 1] - arr[i]) == cd) {
            current_length++;
        } else {
            cd = arr[i + 1] - arr[i];
            current_length = 2; // Reset to 2 since the new subarray starts from current element and the next
        }
        if (current_length > max_length) {
            max_length = current_length;
        }
    }

    cout << "The length of the longest arithmetic subarray is: " << max_length << endl;

    return 0;
}
