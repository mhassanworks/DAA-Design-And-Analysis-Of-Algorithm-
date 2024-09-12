#include <iostream>
using namespace std;

// Function to print the subset
void printSubset(int subset[], int size) {
    for (int i = 0; i < size; i++) {
        cout << subset[i] << " ";
    }
    cout << endl;
}

// Recursive function to find all subsets that sum up to the target
void sumOfSubsets(int set[], int subset[], int setSize, int subsetSize, int total, int target, int index) {
    // If the sum of the subset equals the target, print the subset
    if (total == target) {
        printSubset(subset, subsetSize);
        return;
    }

    // If the sum exceeds the target or all elements have been considered, stop
    if (total > target || index == setSize) {
        return;
    }

    // Include the current element in the subset
    subset[subsetSize] = set[index];
    sumOfSubsets(set, subset, setSize, subsetSize + 1, total + set[index], target, index + 1);

    // Exclude the current element from the subset
    sumOfSubsets(set, subset, setSize, subsetSize, total, target, index + 1);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int target = 35;
    int setSize = sizeof(set) / sizeof(set[0]);
    int subset[setSize];

    cout << "Subsets with sum " << target << " are:" << endl;
    sumOfSubsets(set, subset, setSize, 0, 0, target, 0);

    return 0;
}
