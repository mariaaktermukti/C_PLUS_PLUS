// #include <iostream>
// #include <queue>
// #include <stack>
// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) : data(val), left(nullptr), right(nullptr) {}
// };

// Node* constructTree() {
//     int value;
//     cin >> value;
//     if (value == -1) return nullptr;

//     Node* root = new Node(value);
//     queue<Node*> q;
//     q.push(root);

//     while (!q.empty()) {
//         Node* current = q.front();
//         q.pop();

//         cin >> value;
//         if (value != -1) {
//             current->left = new Node(value);
//             q.push(current->left);
//         }

//         cin >> value;
//         if (value != -1) {
//             current->right = new Node(value);
//             q.push(current->right);
//         }
//     }

//     return root;
// }

// void printLeftBoundary(Node* root) {
//     if (root == nullptr) return;

//     stack<int> s;
//     Node* current = root;
//     while (current) {
//         s.push(current->data);
//         if (current->left)
//             current = current->left;
//         else
//             current = current->right;
//     }
//     while (!s.empty()) {
//         cout << s.top() << " ";
//         s.pop();
//     }
// }

// void printRightBoundary(Node* root) {
//     if (root == nullptr) return;

//     Node* current = root->right;
//     while (current) {
//         cout << current->data << " ";
//         if (current->right)
//             current = current->right;
//         else
//             current = current->left;
//     }
// }

// int main() {
//     Node* root = constructTree();
//     printLeftBoundary(root);
//     printRightBoundary(root);

//     cout << endl;
//     return 0;
// }



#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* constructTree() {
    int value;
    cin >> value;
    if (value == -1) return nullptr;

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cin >> value;
        if (value != -1) {
            current->left = new Node(value);
            q.push(current->left);
        }

        cin >> value;
        if (value != -1) {
            current->right = new Node(value);
            q.push(current->right);
        }
    }

    return root;
}

void printLeftBoundary(Node* root) {
    if (root == nullptr) return;

    stack<int> s;
    Node* current = root;

    if(!root->left) {
    cout << current->data << " ";
    return;
    }
                                                      
    while (current) {
        s.push(current->data);
        if (current->left)
            current = current->left;
        else
            current = current->right;
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

void printRightBoundary(Node* root) {
    if (root == nullptr) return;


       if(!root->right) {
          return;
    }

    Node* current = root->right;
    while (current) {
        cout << current->data << " ";
        if (current->right)
            current = current->right;
        else
            current = current->left;
    }
}

int main() {
    Node* root = constructTree();
    printLeftBoundary(root);
    printRightBoundary(root);

    cout << endl;
    return 0;
}