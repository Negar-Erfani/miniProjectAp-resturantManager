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
    // menu->printItem();
    listOfOrders* ourOrderList = new listOfOrders();
    ourOrderList->readFromFile();
    bool exit = 0;
    string instruct;
    #ifdef _WIN32
        system("chcp 65001 > nul"); 
    #endif
    cout << "☺️ " << "\033[36m" << " your wish is my command" << "\033[0m" << endl;
    cout << "\033[36m" << "\033[5m" <<" you can write " << "\033[4m" << "\033[1m"<<  "getOrder, delete, add, changeStatus, review or any other letter" << "\033[24m" << "\033[22m" << " to leave :"<< "\033[0m" << endl;
    cin >> instruct;
    while(exit != 1)
    {
        cout << "-----------------------------------------------------------"<<endl;
        if(instruct == "getOrder")
        {
            menu->printItem();
            cout << endl;
            ourOrderList->getOrder (menu);
        }
        else if(instruct == "delete")
        {
            int orderNum = 0;
            string singleOrder;
            cout << "please write your order number :" << endl;
            cin >> orderNum;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[31m" << "Not an order number! please try again :" << "\033[0m" << endl;
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
            cout << "please write your order number :" << endl;
            cin >> orderNum;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[31m" << "Not an order number! please try again :" << "\033[0m" << endl;
                cin >> orderNum;
            }
            cout << "please write your order item :" << endl;
            cin >> singleOrder;
            ourOrderList->addOrder(orderNum, singleOrder, menu);
        }
        else if(instruct == "changeStatus")
        {
            int orderNum = 0;
            string newStatus;
            cout << "please write your order number :" << endl;
            cin >> orderNum;
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "\033[31m" <<"Not an order number! please try again :" << "\033[0m" << endl;
                cin >> orderNum;
            }
            cout << "please write the new status you want this order to have :" << endl;
            cout << "\033[35m" << "(possible statuses are : Canceling, Delivered)" << "\033[0m" << endl;
            cin >> newStatus;
            ourOrderList->changeOrderStatus(orderNum, newStatus); 
        }
        else if(instruct == "review")
        {
            ourOrderList->review(); 
        }
        else
        {
            break;
        }
        cout << "-----------------------------------------------------------"<<endl;
        cout << endl;
        cout << "☺️ " << "\033[36m" << " your wish is my command" << "\033[0m" << endl;
        cout << "\033[36m" << "\033[5m" <<" you can write " << "\033[1m"<<  "getOrder, delete, add, changeStatus, review or any other letter" << "\033[24m" << "\033[22m" << " to leave :"<< "\033[0m" << endl;
        cin >> instruct;
    }
    
    
    
    
    
    
    return 0;
}