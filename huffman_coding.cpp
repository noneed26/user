#include <bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct Node
{
    char data;
    int freq;
    Node *left, *right;

    Node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        this->left = this->right = nullptr;
    }
};

// Comparison object to be used to order the heap
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return (l->freq > r->freq);
    }
};

// Function to print Huffman codes from the root of Huffman Tree.
void printCodes(struct Node *root, string str)
{
    if (!root)
        return;

    // If this is a leaf node, print the character and its code
    if (root->data != '$')
    {
        cout << root->data << ": " << str << "\n";
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Function to build the Huffman tree and print codes
void HuffmanCodes(char data[], int freq[], int size)
{
    struct Node *left, *right, *top;

    // Create a min heap & inserts all characters of data[]
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with frequency equal to the
        // sum of the two nodes frequencies. Make the two extracted
        // node as left and right children of this new node. Add
        // this node to the min heap.
        // '$' is a special value for internal nodes, not used
        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print Huffman codes using the Huffman tree built above
    cout << "\nHuffman Codes are:\n";
    printCodes(minHeap.top(), "");
}

int main()
{
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    char data[n];
    int freq[n];

    cout << "Enter the characters and their frequencies:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Character " << i + 1 << ": ";
        cin >> data[i];
        cout << "Frequency of " << data[i] << ": ";
        cin >> freq[i];
    }

    HuffmanCodes(data, freq, n);

    return 0;
}

// tc is O(nlogn)
// O(N)