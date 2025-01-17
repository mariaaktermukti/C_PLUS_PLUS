#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

void collectLeafNodes(TreeNode* root, vector<int>& leafNodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        leafNodes.push_back(root->val);
    } else {
        collectLeafNodes(root->left, leafNodes);
        collectLeafNodes(root->right, leafNodes);
    }
}

int main() {
    vector<int> values;
    int val;
    while (cin >> val) {
        values.push_back(val);
    }

    TreeNode* root = buildTree(values);

    vector<int> leafNodes;
    collectLeafNodes(root, leafNodes);

    sort(leafNodes.rbegin(), leafNodes.rend());

    for (int v : leafNodes) {
        cout << v << " ";
    }

    return 0;
}