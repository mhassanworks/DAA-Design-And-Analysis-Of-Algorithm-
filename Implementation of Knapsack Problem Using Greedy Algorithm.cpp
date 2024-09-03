#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store the weight and value of each item
struct Item {
    int value;
    int weight;
    
    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by value/weight ratio
bool cmp(const Item &a, const Item &b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate the maximum value of items in the knapsack
double fractionalKnapsack(int W, vector<Item> &items) {
    // Sort items by value/weight ratio in descending order
    sort(items.begin(), items.end(), cmp);
    
    int curWeight = 0; // Current weight in the knapsack
    double finalValue = 0.0; // Final value of the knapsack
    
    // Iterate through the items
    for (const Item &item : items) {
        if (curWeight + item.weight <= W) {
            // Take the whole item
            curWeight += item.weight;
            finalValue += item.value;
        } else {
            // Take the fraction of the item
            int remain = W - curWeight;
            finalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }
    
    return finalValue;
}

int main() {
    int W = 50; // Maximum weight of knapsack
    vector<Item> items;
    
    // Add items (value, weight)
    items.emplace_back(60, 10);
    items.emplace_back(100, 20);
    items.emplace_back(120, 30);
    
    // Calculate the maximum value that can be obtained
    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;
    
    return 0;
}
