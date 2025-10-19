#include <iostream>
#include <string>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include "Order.h"
#include "linkedlist.h"
#include "AVL.h"
using namespace std;

int Order::counter = 0;
Order::Order(string name, int customerId, linkedlist* ordered) : customerName(name), customerId(customerId)
{
    counter++;
    orderNum = counter;
    orderStatus = "Processing";
    orderedItems = ordered;
}
void Order::changeStatus (string newStatus)
{
    this->orderStatus = newStatus;
}
