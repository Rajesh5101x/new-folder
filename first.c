#include <iostream>
#include <vector>

int main() {
    int arr[] = {10, 7, 4, 6, 8, 10, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int cd = arr[1] - arr[0];  // Common difference of the initial two elements
    int maxSubArray = 2;       // Length of the longest subarray found
    int currentSubArray = 2;   // Length of the current subarray being checked

    // Vectors to hold the current and maximum subarrays
    std::vector<int> max = {arr[0], arr[1]};
    std::vector<int> curr = {arr[0], arr[1]};

    for (int i = 2; i < size; i++) {
        if (arr[i] - arr[i - 1] == cd) {
            // Continue the current subarray
            currentSubArray++;
            curr.push_back(arr[i]);
        } else {
            // Check if the current subarray is the longest so far
            if (currentSubArray > maxSubArray) {
                maxSubArray = currentSubArray;
                max = curr; // Copy the current subarray to max
            }
            // Start a new subarray
            curr = {arr[i - 1], arr[i]};
            cd = arr[i] - arr[i - 1];
            currentSubArray = 2;
        }
    }

    // Check the last subarray
    if (currentSubArray > maxSubArray) {
        max = curr;
    }

    // Output the maximum subarray
    std::cout << "Maximum subarray with the same common difference: ";
    for (int i = 0; i < max.size(); ++i) {
        std::cout << max[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
