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

int count_nodes(Node* root)
{
    if (root == NULL) {
        return 0; // Base case: no nodes in an empty tree
    }
    int l = count_nodes(root->left);  // Count nodes in the left subtree
    int r = count_nodes(root->right); // Count nodes in the right subtree
    return l + r + 1; // Total nodes = left subtree + right subtree + current node
}

int main() {
    cout << "Enter the values for the binary tree:" << endl;
    Node* root = input_tree();

    cout << "Level order traversal of the binary tree:" << endl;
    print_tree(root);

    cout << "Total number of nodes in the binary tree: " << count_nodes(root) << endl;

    return 0;
}
