#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 1. Function to search for a key in the BST
bool search(TreeNode* root, int k) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == k) {
        return true;
    } else if (k < root->value) {
        return search(root->left, k);
    } else {
        return search(root->right, k);
    }
}

// 2. Function to insert a key into the BST
void insert(TreeNode*& root, int k) {
    if (root == nullptr) {
        root = new TreeNode(k);
    } else if (k < root->value) {
        insert(root->left, k);
    } else if (k > root->value) {
        insert(root->right, k);
    }
    // Do nothing if k == root->value (key is already present)
}

// 3. Function to find the largest element less than k
TreeNode* findMaxLessThan(TreeNode* root, int k) {
    TreeNode* current = root;
    TreeNode* best = nullptr;

    while (current != nullptr) {
        if (current->value < k) {
            best = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return best;
}

// 4. Function to print the BST in level-order
void printLevelOrder(TreeNode* root) {
    if (root == nullptr) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->value << " ";
            if (node->left != nullptr) q.push(node->left);
            if (node->right != nullptr) q.push(node->right);
        }
        std::cout << std::endl;
    }
}

int main() {
    TreeNode* root = nullptr;
    int numNodes, key;

    cout << "Enter the number of nodes to insert: ";
    cin >> numNodes;

    cout << "Enter the values of the nodes: " << endl;
    for (int i = 0; i < numNodes; ++i) {
        cin >> key;
        insert(root, key);
    }

    cout << "BST in level-order:" << endl;
    printLevelOrder(root);

    cout << "Enter a key to search for: ";
    cin >> key;
    cout << (search(root, key) ? "Found "  : "Not Found ") << key << endl;

    cout << "Enter a key to find the largest element less than it: ";
    cin >> key;

    TreeNode* result = findMaxLessThan(root, key);

    if (result) {
        cout << "Max element less than " << key << " is " << result->value << endl;
    } else {
        cout << "No element less than " << key << endl;
    }

    return 0;
}
