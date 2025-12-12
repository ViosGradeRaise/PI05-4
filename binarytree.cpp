#include <iostream>

// Определим структуру для узла в дереве
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Функция для вставки нового узла в дерево
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Функция для выполнения обхода дерева по порядку
void inorder_traversal(Node* root) {
    if (root != nullptr) {
        inorder_traversal(root->left);
        std::cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Обход по порядку:
    std::cout << "Обход по порядку: ";
    inorder_traversal(root);
    std::cout << std::endl;

    return 0;
}
