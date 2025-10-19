#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "linkedlist.h"
#include <utility>
using namespace std;

struct Order {
    static int counter;  //used to acknowledge orderId
    int orderNum;        
    string customerName;  
    int customerId;  
    linkedlist* orderedItems; 
    string orderStatus;     
    Order(string name, int customerId, linkedlist* ordered);
    void changeStatus (string newStatus);
};