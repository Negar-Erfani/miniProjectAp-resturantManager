#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
#include "Order.h"
using namespace std;

int Order::counter = 0;
Order::Order(int id, string name) : customerId(id), customerName(name)
{
    counter++;
    orderId = counter;
    status = Processing;

};