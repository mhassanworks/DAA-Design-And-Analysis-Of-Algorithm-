#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Binary search function
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;

    // Sort the array (Binary search requires a sorted array)
    sort(arr.begin(), arr.end());

    int result = binarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found in array" << endl;
    }

    return 0;
}
