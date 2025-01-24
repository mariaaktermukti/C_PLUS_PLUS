#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};

bool searchInBST(BinaryTreeNode<int> *root, int x) 
{
    while (root != NULL) 
    {
        if (root->data == x) 
        {
            return true;
        } 
        else if (x < root->data) 
        {
            root = root->left;
        } 
        else 
        {
            root = root->right;
        }
    }
    return false;
}

BinaryTreeNode<int>* buildTree() 
{
    int rootData;
    cin >> rootData;
    if (rootData == -1) return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) 
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) 
        {
            front->left = new BinaryTreeNode<int>(leftChild);
            q.push(front->left);
        }

        cin >> rightChild;
        if (rightChild != -1) 
        {
            front->right = new BinaryTreeNode<int>(rightChild);
            q.push(front->right);
        }
    }

    return root;
}

int main() 
{
    int n, x;
    cin >> n >> x;

    BinaryTreeNode<int> *root = buildTree();

    if (searchInBST(root, x)) 
    {
        cout << "True" << endl;
    } 
    else 
    {
        cout << "False" << endl;
    }

    return 0;
}
