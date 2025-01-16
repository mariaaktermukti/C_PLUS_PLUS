#include <bits/stdc++.h>
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

Node* buildTree(const vector<int>& nodes) 
{
    if (nodes.empty() || nodes[0] == -1) return nullptr; 

    queue<Node*> q;
    Node* root = new Node(nodes[0]);
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < nodes.size()) 
    {
        Node* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) 
        {
            current->left = new Node(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) 
        {
            current->right = new Node(nodes[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int sumNonLeafNodes(Node* root) 
{
    if (!root) return 0; 

    int sum = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();
        if (current->left || current->right) 
        {
            sum += current->val;
        }
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }

    return sum;
}

int main() {
    string input;
    getline(cin, input);

    vector<int> nodes;
    stringstream ss(input);
    int num;
    while (ss >> num) 
    {
        nodes.push_back(num);
    }
    Node* root = buildTree(nodes);
    cout << sumNonLeafNodes(root) << endl;

    return 0;
}
