#include <bits/stdc++.h>
using namespace std;

    template <typename T>
    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

bool isPartialBST(BinaryTreeNode<int> *root, int minValue, int maxValue) 
{
    if (!root) return true; 
    if (root->data < minValue || root->data > maxValue) return false;
    return isPartialBST(root->left, minValue, root->data) &&
           isPartialBST(root->right, root->data, maxValue);
}

bool validateBST(BinaryTreeNode<int> *root) 
{
    return isPartialBST(root, INT_MIN, INT_MAX);
}

BinaryTreeNode<int>* buildTree(const vector<int> &levelOrder) 
{
    if (levelOrder.empty() || levelOrder[0] == -1) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(levelOrder[0]);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    int index = 1;
    while (!q.empty() && index < levelOrder.size()) 
    {
        BinaryTreeNode<int>* current = q.front();
        q.pop();

        if (levelOrder[index] != -1) 
        {
            current->left = new BinaryTreeNode<int>(levelOrder[index]);
            q.push(current->left);
        }
        index++;

        if (index < levelOrder.size() && levelOrder[index] != -1) 
        {
            current->right = new BinaryTreeNode<int>(levelOrder[index]);
            q.push(current->right);
        }
        index++;
    }
    return root;
}

int main() {
    int t; 
    cin >> t;

    while (t--) {
        vector<int> levelOrder;
        int nodeValue;

        while (cin >> nodeValue) 
        {
            levelOrder.push_back(nodeValue);
            if (cin.peek() == '\n') break;
        }

        BinaryTreeNode<int>* root = buildTree(levelOrder);

        if (validateBST(root)) 
        {
            cout << "true" << endl;
        } 
        else 
        {
            cout << "false" << endl;
        }
    }

    return 0;
}
