#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "linkedlist.h"
#include <utility>using namespace std;

struct Order {
    static int counter;  //used to acknowledge orderId
    string customerName;  
    int customerId;  
    int orderId;        
    string status;     
    linkedlist* orderedItems; 
    Order(int customerId, string name, linkedlist* ordered);
    void changeStatus (int orderId, string newStatus);
};