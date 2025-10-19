#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
#include "Order.h"
using namespace std;

struct Node
{
    Order data;
    Node* left;
    Node* right;
    int height;
    Node(Order value);
};

class AVLTree 
{
private:
    Node* root;

    int getHeight(Node* node);
    int getBalance(Node* node);
    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* insertHelper (Node* node, Order value);
    Node* searchHelper(Node* node, int orderId);
    void inorderHelper(Node* node);
    void writeInFile();

public:
    AVLTree();
    void insert(Order value);
    bool search(int orderId);
    void inorder();
};