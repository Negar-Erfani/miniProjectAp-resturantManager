#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "linkedlist.h"
#include "listOfOrders.h"
#include "AVL.h"
#include "Menu.h"
#include "Order.h"
#include <utility>
using namespace std;

void listOfOrders::getOrder()
{
    string name;
    int studentId;
    linkedlist* orderedItems;
    cout << "please enter customer's name :" << endl;
    cin >> name;
    cout << "please enter customer's studentID :" << endl;
    cin >> studentId;
    while(cin.fail() || to_string(studentId).size() != 8)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Not a studentID. please try again :" << endl;
        cin >> studentId;
    }
    cout << "please enter customer's order. write end when you are done :" << endl;
    string temp3;
    cin >> temp3;
    while(temp3=="end")
    {
    cout << "You didn't enter any order!" << endl;
    cout << "please try again :"<<endl;
    cin >> temp3;
    }
    while(temp3 != "end")
    {
        orderedItems->insert(temp3);
        cin >> temp3;
    }
    Order currentOrder = Order(name, studentId, orderedItems);
    orderList->insert(currentOrder);

    ofstream orderInfo("order informations", ios::app);
    orderInfo << currentOrder.orderNum << " " << currentOrder.customerName << " " << currentOrder.customerId << " ";
    cout << currentOrder.orderedItems->asLine();
    orderInfo.close();
    

}