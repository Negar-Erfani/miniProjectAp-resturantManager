#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "linkedlist.h"
#include "Menu.h"
#include "Order.h"
#include <utility>
using namespace std;

class AVLTree {
    public: 
    struct Node {
        Order data;
        Node* left;
        Node* right;
        int height;
        Node(Order val) : data(val), left(nullptr), right(nullptr), height(1) {}
    };
    Node* root;
private:


int getHeight(Node* node);
int getBalance(Node* node);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
Node* insert(Node* node, Order val);
Node* minValueNode(Node* node);
Node* remove(Node* node, Order val);
void inorder(Node* node);

public:    
AVLTree() : root(nullptr) {}
    void insert(Order val);
    void remove(Order val);
    AVLTree::Node* search(int orderNum);
    void inorderTraversal();
    vector <Node*> inorderNodes (Node* node);
};
