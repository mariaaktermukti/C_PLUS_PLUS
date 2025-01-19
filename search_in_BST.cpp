#include<bits/stdc++.h>
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
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node* myLeft = nullptr;
        Node* myRight = nullptr;
        
        if (l != -1) {
            myLeft = new Node(l);
            q.push(myLeft);
        }
        if (r != -1) {
            myRight = new Node(r);
            q.push(myRight);
        }

        f->left = myLeft;
        f->right = myRight;
    }
    
    return root;
}

bool search(Node* root, int val) {
    if (root == nullptr) {
        return false;
    }
    if (root->val == val) {
        return true;
    }

    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

int main() {
    Node* root = input_tree();
    int val;
    cin >> val;
    if (search(root, val)) {
        cout << "Found\n";
    } else {
        cout << "Not Found\n";
    }

    return 0;
}
