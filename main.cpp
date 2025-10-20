#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
#include <sstream>
#include "linkedlist.h"
#include "Menu.h"
#include "MenuItem.h"
#include "Order.h"
#include "listOfOrders.h"
#include "AVL.h"
using namespace std;

int main() {

    Menu* menu = new Menu();
    MenuItem* food = new MenuItem("food", menu);
    MenuItem* apetizer = new MenuItem("apetizer", menu);
    MenuItem* drink = new MenuItem("drink", menu);
    menu->printItem();
    listOfOrders* ourOrderList = new listOfOrders();
    ourOrderList->readFromFile();
    bool exit = 0;
    string instruct;
    string instructTemp;
    cin >> instruct;
    while(exit != 1)
    {
        if(instruct == "get order")
        {
            ourOrderList->getOrder (menu);
        }
        else if(instruct == "delete")
        {
            int orderNum = 0;
            string singleOrder;
            cout << "please write your order number" << endl;
            cin >> orderNum;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Not a order number! please try again :" << endl;
                cin >> orderNum;
            }
            cout << "please write your order item :" << endl;
            cin >> singleOrder;
            ourOrderList->deleteOrder(orderNum, singleOrder);
        }
        else if(instruct == "add")
        {
            int orderNum = 0;
            string singleOrder;
            cout << "please write your order number" << endl;
            cin >> orderNum;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Not a order number! please try again :" << endl;
                cin >> orderNum;
            }
            cout << "please write your order item :" << endl;
            cin >> singleOrder;
            ourOrderList->addOrder(orderNum, singleOrder, menu);
        }
        else if(instruct == "chande status")
        {
            int orderNum = 0;
            string newStatus;
            cout << "please write your order number" << endl;
            cin >> orderNum;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Not a order number! please try again :" << endl;
                cin >> orderNum;
            }
            cout << "please write the new status you want this order to have :" << endl;
            cin >> newStatus;
            ourOrderList->changeOrderStatus(orderNum, newStatus); 
        }
        else if(instruct == "review")
        {
            ourOrderList->review(); 
        }
        cout << endl;
}



    


    return 0;
}