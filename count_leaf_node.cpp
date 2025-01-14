#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;
    if (val == -1) return NULL; // If the root is -1, return NULL

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) {
            f->left = new Node(l);
            q.push(f->left);
        }
        if (r != -1) {
            f->right = new Node(r);
            q.push(f->right);
        }
    }

    return root;
}

void print_tree(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left) q.push(f->left);
        if (f->right) q.push(f->right);
    }
    cout << endl;
}

int count_leaf_nodes(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        return 1; // Current node is a leaf
    }

    // Count leaf nodes in left and right subtrees
    int left_leaves = count_leaf_nodes(root->left);
    int right_leaves = count_leaf_nodes(root->right);

    return left_leaves + right_leaves;
}

int main() {
    cout << "Enter the values for the binary tree:" << endl;
    Node* root = input_tree();

    cout << "Level order traversal of the binary tree:" << endl;
    print_tree(root);

    int leaf_count = count_leaf_nodes(root);
    cout << "Total number of leaf nodes in the binary tree: " << leaf_count << endl;

    return 0;
}
