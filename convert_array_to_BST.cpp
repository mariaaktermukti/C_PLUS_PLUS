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

Node* convert(vector<int>& a, int l, int r) {
    if (l > r) return NULL;
    int mid = (l + r) / 2;
    Node* root = new Node(a[mid]);
    root->left = convert(a, l, mid - 1);
    root->right = convert(a, mid + 1, r);
    return root;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Node* root = convert(a, 0, n - 1);
    level_order(root);
    return 0;
}
