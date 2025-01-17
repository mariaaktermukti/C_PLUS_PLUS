#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree() {
    int val;
    cin >> val;

    if (val == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cin >> val;
        if (val != -1) {
            node->left = new TreeNode(val);
            q.push(node->left);
        }

        cin >> val;
        if (val != -1) {
            node->right = new TreeNode(val);
            q.push(node->right);
        }
    }

    return root;
}

void printLevel(TreeNode* root, int level) {
    if (!root) {
        cout << "Invalid" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    int currentLevel = 0;

    while (!q.empty()) {
        int size = q.size();

        if (currentLevel == level) {
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                cout << node->val << " ";
            }
            cout << endl;
            return;
        }

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        currentLevel++;
    }
    cout << "Invalid" << endl;
}

int main() {
    TreeNode* root = buildTree();
    int level;
    cin >> level;
    printLevel(root, level);

    return 0;
}
