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
    if (val == -1) return NULL; 

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        Node* f = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) 
        {
            f->left = new Node(l);
            q.push(f->left);
        }
        if (r != -1) 
        {
            f->right = new Node(r);
            q.push(f->right);
        }
    }

    return root;
}

bool search(Node* root, int X) 
{
    if (root == NULL) 
    {
        return false;
    }
    if 
    (root->val == X) 
    {
        return true;
    }
    return search(root->left, X) || search(root->right, X);
}

int main() {
    Node* root = input_tree();
    
    int X;
    cin >> X;
    if (search(root, X)) 
    {
        cout << "true" << endl;
    } 
    else 
    {
        cout << "false" << endl;
    }

    return 0;
}
