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
Order::Order(int customerId, string name, linkedlist* ordered ) : customerId(customerId), customerName(name)
{
    counter++;
    orderId = counter;
    status = "Processing";
    orderedItems = ordered;
}
