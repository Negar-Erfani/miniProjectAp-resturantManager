#include "AVL.h"
#include "Order.h"
#include <algorithm> // for std::max
using namespace std;

int AVLTree::getHeight(Node* node) {
    if (node == nullptr) return 0;
    return node->height;
}

int AVLTree::getBalance(Node* node) {
    if (node == nullptr) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

typename AVLTree::Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

typename AVLTree::Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

typename AVLTree::Node* AVLTree::insert(Node* node, Order val) {
    if (node == nullptr) return new Node(val);

    if (val.orderNum < node->data.orderNum)
        node->left = insert(node->left, val);
    else if (val.orderNum >node->data.orderNum)
        node->right = insert(node->right, val);
    else
        return node; 

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && val.orderNum < node->left->data.orderNum)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && val.orderNum > node->right->data.orderNum)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && val.orderNum > node->left->data.orderNum) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && val.orderNum < node->right->data.orderNum) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::insert(Order val) {
    root = insert(root, val);
}

typename AVLTree::Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

typename AVLTree::Node* AVLTree::remove(Node* node, Order val) {
    if (node == nullptr) return node;

    if (val.orderNum < node->data.orderNum)
        node->left = remove(node->left, val);
    else if (val.orderNum > node->data.orderNum)
        node->right = remove(node->right, val);
    else {
        if ((node->left == nullptr) || (node->right == nullptr)) {
            Node* temp = node->left ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }

    if (node == nullptr) return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right Case
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right Case
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left Case
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void AVLTree::remove(Order val) {
    root = remove(root, val);
}

AVLTree::Node* AVLTree::search(int orderNum) {
    Node* current = root;
    while (current != nullptr) {
        if (orderNum == current->data.orderNum)
            return current;
        else if (orderNum < current->data.orderNum)
            current = current->left;
        else
            current = current->right;
    }
    return nullptr;
}

void AVLTree::inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->data.orderNum << " " << node->data.customerName << node->data.customerId  << " ";
        node->data.orderedItems->display();
        inorder(node->right);
    }
}

void AVLTree::inorderTraversal() {
    inorder(root);
    cout << endl;
}
