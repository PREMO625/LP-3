#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct Node {
    char ch;
    long long frequency;
    Node* left;
    Node* right;

    Node(char c, long long f, Node* l = nullptr, Node* r = nullptr)
        : ch(c), frequency(f), left(l), right(r) {}
};

struct CompareNodes {
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void generateCodes(Node* root, const string& code, map<char, string>& codes) {
    if (root == nullptr) return;

    if (root->left == nullptr && root->right == nullptr) {
        codes[root->ch] = code.empty() ? "0" : code;
        return;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    if (!cin || n <= 0) {
        cout << "Invalid number of characters.\n";
        return 1;
    }

    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;
    set<char> characters;
    cout << "Enter each character and its frequency:\n";

    for (int i = 0; i < n; i++) {
        char character;
        long long frequency;
        cin >> character >> frequency;

        if (!cin || frequency <= 0) {
            cout << "Frequency must be positive.\n";
            return 1;
        }

        if (!characters.insert(character).second) {
            cout << "Duplicate characters are not allowed.\n";
            return 1;
        }

        minHeap.push(new Node(character, frequency));
    }

    while (minHeap.size() > 1) {
        Node* first = minHeap.top();
        minHeap.pop();
        Node* second = minHeap.top();
        minHeap.pop();

        minHeap.push(new Node('$', first->frequency + second->frequency,
                              first, second));
    }

    Node* root = minHeap.top();
    map<char, string> codes;
    generateCodes(root, "", codes);

    cout << "\nHuffman Codes:\n";
    for (const auto& code : codes)
        cout << code.first << " : " << code.second << '\n';

    deleteTree(root);
    return 0;
}