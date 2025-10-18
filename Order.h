#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
using namespace std;

enum statusKey {Processing = 1, Delivered, canceled};
struct Order {
    static int counter;
    string customerName;  
    int customerId;  
    int orderId;        
    int status;      
    Order(int id, string name){};
};