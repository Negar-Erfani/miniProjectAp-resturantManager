#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
#include "linkedlist.h"
#include "Menu.h"
#include "MenuItem.h"
#include "Order.h"
#include "listOfOrders.h"
#include "AVL.h"
using namespace std;

int main() {
    // از روی فایل لینک لیست مربوط به هر کدوم رو پر کن
    Menu* menu = new Menu();
    MenuItem* food = new MenuItem("food", menu);
    MenuItem* apetizer = new MenuItem("apetizer", menu);
    MenuItem* drink = new MenuItem("drink", menu);
    menu->printItem();
    listOfOrders* ourOrderList = new listOfOrders();
    ourOrderList->readFromFile();
    // for (size_t i = 0; i < 3; i++)
    // {
    //     ourOrderList->getOrder(); 
    // }
    // ourOrderList->deleteOrder(1, "egg");
    ourOrderList->replaceOrder(4, "CocaCola", "Soda");
    // ourOrderList->addOrder(3, "CocaCola");
    // ourOrderList->changeOrderStatus(1, "Canceling");
    ourOrderList->review();


    


    return 0;
}