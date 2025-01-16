#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode class
template <typename T>
class TreeNode {
   public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

// Function to find the level of a node with a given value
int nodeLevel(TreeNode<int>* root, int searchedValue) {
    if (!root) return 0; // If the tree is empty, return 0

    queue<TreeNode<int>*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode<int>* current = q.front();
            q.pop();

            if (current->val == searchedValue) {
                return level;
            }

            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        level++;
    }

    return 0; // If the node is not found, return 0
}

// Utility function to build a binary tree from input
TreeNode<int>* buildTree(vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    TreeNode<int>* root = new TreeNode<int>(nodes[0]);
    queue<TreeNode<int>*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode<int>* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode<int>(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode<int>(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        vector<int> nodes;
        int val;
        while (cin >> val && val != -2) { // Use -2 as a delimiter for input
            nodes.push_back(val);
        }

        int M;
        cin >> M; // Node value to search for

        TreeNode<int>* root = buildTree(nodes);
        cout << nodeLevel(root, M) << endl;

        // Free allocated memory (optional but good practice)
        // Add a utility function to free tree if needed
    }

    return 0;
}
