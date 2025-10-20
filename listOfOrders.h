#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "linkedlist.h"
#include "AVL.h"
#include <utility>
using namespace std;

enum orderInstruction{deleting = 1, replacing, adding};
class listOfOrders
{
    public:
    AVLTree* orderList;
    void getOrder ();
    void readFromFile();
    void rewriteFile();
    void deleteOrder(int OrderNum, string singleOrder);
};

