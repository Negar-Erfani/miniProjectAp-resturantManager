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

class listOfOrders
{
    public:
    AVLTree* orderList;
    void getOrder ();
};

