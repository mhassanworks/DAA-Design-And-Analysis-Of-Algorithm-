#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// A Huffman tree node
struct MinHeapNode {
    char data;              // One of the input characters
    int freq;               // Frequency of the character
    MinHeapNode *left, *right; // Left and right child

    MinHeapNode(char data, int freq) {
        left = right = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

// Comparison object to be used to order the heap
struct compare {
    bool operator()(MinHeapNode* left, MinHeapNode* right) {
        return (left->freq > right->freq);
    }
};

// Prints Huffman codes from the root of Huffman Tree
void printCodes(struct MinHeapNode* root, string str) {
    if (!root)
        return;

    if (root->data != '$')
        cout << root->data << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// The main function that builds a Huffman Tree and prints codes by traversing the built Huffman Tree
void HuffmanCodes(vector<char>& data, vector<int>& freq, int size) {
    struct MinHeapNode *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    // Iterate while the size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the sum of the two nodes frequencies.
        // Make the two extracted nodes as left and right children of this new node. Add this node to the min heap.
        // '$' is a special value for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}

int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    int size = data.size();
    HuffmanCodes(data, freq, size);

    return 0;
}
