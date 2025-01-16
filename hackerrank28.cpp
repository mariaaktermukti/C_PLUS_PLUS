//perfect binary tree
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int key;
    struct Node *left, *right;
};

int depth(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    int leftDepth = depth(node->left);
    int rightDepth = depth(node->right);
    return max(leftDepth, rightDepth) + 1;
}

bool isPerfectR(Node* root, int d, int level = 0) {
    if (root == nullptr)
        return true;

    // If it's a leaf node
    if (root->left == nullptr && root->right == nullptr)
        return (d == level + 1); 

    if (root->left == nullptr || root->right == nullptr)
        return false;

    return isPerfectR(root->left, d, level + 1) && isPerfectR(root->right, d, level + 1);
}

bool isPerfect(Node* root) {
    int d = depth(root);
    return isPerfectR(root, d);
}

Node* newNode(int k) {
    Node* node = new Node;
    node->key = k;
    node->left = node->right = nullptr;
    return node;
}


Node* buildTree(const vector<int>& input) {
    if (input.empty() || input[0] == -1) return nullptr;

    Node* root = newNode(input[0]);
    queue<Node*> q;
    q.push(root);

    size_t i = 1;  
    while (i < input.size()) {
        Node* current = q.front();
        q.pop();

        if (input[i] != -1) {
            current->left = newNode(input[i]);
            q.push(current->left);
        }
        i++;

        if (i < input.size() && input[i] != -1) {
            current->right = newNode(input[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    vector<int> input;
    int val;

    while (cin >> val) {
        input.push_back(val);
    }

    Node* root = buildTree(input);

    if (isPerfect(root)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
