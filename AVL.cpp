#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include "Order.h"
#include "AVL.h"
using namespace std;

Node::Node(Order value) : data(value), left(nullptr), right(nullptr), height(1) {};

AVLTree::AVLTree()
{
    
    string fileName = "orderInfo.txt";
    ifstream file;
    file.open(fileName);
    string temp;

    if (!file.is_open())
    {
        root = nullptr;
    }
    string line, templine;

    if(file.is_open())
    {
        file.seekg(0, ios::beg);
        linkedlist* ordered = new linkedlist();
        vector <string> info;
        int orderId;
        while (getline(file, line)) 
        {
            stringstream ss (line);
            while(ss >> templine)
            {
                info.push_back(templine);
            }
            for (size_t i = 3; i < info.size()-1; i++)
            {
                ordered->insert(info.at(i));
            }
            
        Order orderTemp =  Order(stoi(info.at(2)), info.at(1), ordered);
        orderTemp.changeStatus(stoi(info.at(0)),info.at(info.size()-1));
        insert(orderTemp);
        }
        file.close();
    }
};

int AVLTree::getHeight(Node* node) 
{
    return node ? node->height : 0;
}

int AVLTree::getBalance(Node* node) 
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* AVLTree::rightRotate(Node* y) 
{
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
}

Node* AVLTree::leftRotate(Node* x) 
{
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
}

Node* AVLTree::insertHelper(Node* node, Order value) 
{
        if (!node) return new Node(value);
        if (value.orderId < node->data.orderId)
            node->left = insertHelper(node->left, value);
        else if (value.orderId > node->data.orderId)
            node->right = insertHelper(node->right, value);
        else
            return node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        int balance = getBalance(node);

        if (balance > 1 && value.orderId < node->left->data.orderId)
            return rightRotate(node);

        if (balance < -1 && value.orderId > node->right->data.orderId)
            return leftRotate(node);
  
        if (balance > 1 && value.orderId > node->left->data.orderId) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value.orderId < node->right->data.orderId) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
}

Node* AVLTree::searchHelper(Node* node, int orderId) 
{
        if (!node || node->data.orderId == orderId)
            return node;
        if (orderId < node->data.orderId)
            return searchHelper(node->left, orderId);
        return searchHelper(node->right, orderId);
}

void AVLTree::inorderHelper(Node* node) 
{
        if (node) {
            inorderHelper(node->left);
            cout << "Order ID: " << node->data.orderId << ", Customer: " << node->data.customerName
                 << ", Status: " << node->data.status << endl;
            inorderHelper(node->right);
        }
}

AVLTree::AVLTree() : root(nullptr) {};

void AVLTree::insert(Order value) 
{
    this->root = insertHelper(this->root, value);
}

bool AVLTree::search(int orderId) 
{
        Node* result = searchHelper(root, orderId);
        if (result) {
            cout << "Found: Order ID: " << result->data.orderId << ", Customer: "
                 << result->data.customerName << ", Status: " << result->data.status << endl;
            return true;
        }
        return false;
}

void AVLTree::inorder() 
{
        inorderHelper(root);
        cout << endl;
}