#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void level_order(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();

        cout << f->val << " ";

        if (f->left)
            q.push(f->left);
        if (f->right)
            q.push(f->right);
    }
}

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *myLeft, *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

vector<int> leftmost(Node* root) {
    vector<int> path;
    Node* temp = root;
    while (temp) {
        path.push_back(temp->val);
        if (temp->left)
            temp = temp->left;
        else if (temp->right)
            temp = temp->right;
        else
            break;
    }
    return path;
}

vector<int> rightmost(Node* root) {
    vector<int> path;
    Node* temp = root;
    while (temp) {
        path.push_back(temp->val);
        if (temp->right)
            temp = temp->right;
        else if (temp->left)
            temp = temp->left;
        else
            break;
    }
    return path;
}

void print(Node* root) {
    if (!root) return;
    vector<int> left = leftmost(root);
    vector<int> right = rightmost(root);

    for (int i = left.size() - 1; i >= 0; --i)
        cout << left[i] << " ";

    for (int i = 1; i < right.size(); ++i)
        cout << right[i] << " ";
}

int main()
{
    Node *root = input_tree();
    print(root);
    return 0;
}