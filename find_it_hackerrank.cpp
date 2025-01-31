#include <iostream>
#include <vector>

using namespace std;

void collectLeaves(const vector<int>& tree, int index, vector<int>& leaves) {
    if (index >= tree.size() || index < 0 || tree[index] == -1) return; 

    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if ((leftChild >= tree.size() || tree[leftChild] == -1) &&
        (rightChild >= tree.size() || tree[rightChild] == -1)) {
        leaves.push_back(tree[index]);
    } else {
        collectLeaves(tree, leftChild, leaves);
        collectLeaves(tree, rightChild, leaves);
    }
}

int main() {
    vector<int> tree;
    int num;

    while (cin >> num) {
        tree.push_back(num);
    }

    if (tree.empty()) {
        cerr << "Error: Empty input" << endl;
        return 1;  
    }

    vector<int> leaves;
    collectLeaves(tree, 0, leaves);

    int leafCount[101] = {0};  
    for (int leaf : leaves) {
        leafCount[leaf]++;
    }

    int mostFrequent = -1, maxFrequency = 0;
    for (int i = 1; i <= 100; ++i) {
        if (leafCount[i] > maxFrequency || 
           (leafCount[i] == maxFrequency && i < mostFrequent)) {
            mostFrequent = i;
            maxFrequency = leafCount[i];
        }
    }

    cout << mostFrequent << endl;

    return 0;
}
