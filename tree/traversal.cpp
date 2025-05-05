#include <iostream>
#include <queue> // For BFS

using namespace std;

// Definition of a simple binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Preorder Traversal: Root → Left → Right
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal: Left → Root → Right
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal: Left → Right → Root
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order Traversal (BFS)
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left)  q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

int main() {
    // Sample tree:
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Preorder: "; preorder(root); cout << "\n";
    cout << "Inorder: "; inorder(root); cout << "\n";
    cout << "Postorder: "; postorder(root); cout << "\n";
    cout << "Level Order: "; levelOrder(root); cout << "\n";

    return 0;
}
