#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
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

void level_order(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left) {
            q.push(f->left);
        }
        if (f->right) {
            q.push(f->right);
        }
    }
    cout << endl;
}

void insert(Node*& root, int val) {
    if (root == nullptr) 
    {
        root = new Node(val);
        return;
    }
    if (val < root->val) 
    {
        // Insert into the left subtree
        if (root->left == nullptr) 
        {
            root->left = new Node(val);
        } 
        else 
        {
            insert(root->left, val);
        }
    } 
    else 
    {
        // Insert into the right subtree
        if (root->right == nullptr) 
        {
            root->right = new Node(val);
        } 
        else 
        {
            insert(root->right, val);
        }
    }
}

int main() {
    Node* root = input_tree();
    int val;
    cin >> val;
    insert(root, val);
    level_order(root);
    return 0;
}
