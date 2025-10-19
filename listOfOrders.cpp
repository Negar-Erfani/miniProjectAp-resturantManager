#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include "linkedlist.h"
#include "listOfOrders.h"
#include "AVL.h"
#include "Menu.h"
#include "Order.h"
#include <utility>
using namespace std;

void listOfOrders::readFromFile()
{
    orderList = new AVLTree();
    string lineOrder, tempOrder;
    vector <string> LineOrder;
    ifstream orderInfo("order information.txt");
    if(orderInfo.is_open())
    {
        while(getline(orderInfo, lineOrder))
        {
            stringstream ss (lineOrder);
            {
                while(ss >> tempOrder)
                {
                    LineOrder.push_back(tempOrder);
                }
            }
            linkedlist* tempLinkedlist = new linkedlist();
            for (size_t i = 3; i < LineOrder.size()-2; i++)
            {
                tempLinkedlist->insert(LineOrder.at(i));
            }
            Order* order = new Order(LineOrder.at(1), stoi(LineOrder.at(2)), tempLinkedlist);
            order->changeStatus(LineOrder.at(LineOrder.size()-1));
            order->orderNum = stoi(LineOrder.at(0));
            // order->counter = stoi(LineOrder.at(0));
            delete tempLinkedlist;
            delete order;
        }
    }
    else
    {
        cout << "LIST failed" << endl;
    }
    orderInfo.close();
}
void listOfOrders::getOrder()
{
    string name;
    int studentId;
    linkedlist* orderedItems = new linkedlist();
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
    // orderList = new AVLTree();
    orderList->insert(currentOrder);

    ofstream orderInfo("order information.txt", ios::app);
    orderInfo << currentOrder.orderNum << " " << currentOrder.customerName << " " << currentOrder.customerId << " ";
    orderInfo << currentOrder.orderedItems->asLine() << currentOrder.orderStatus << "\n";
    orderInfo.close();
    

}
void listOfOrders::deleteOrder(int OrderNum, string singleOrder)
{
    AVLTree::Node* targetOrder = orderList->search(OrderNum);
    if(targetOrder->data.orderedItems->getNum() > 1)
    {
    targetOrder->data.orderedItems->remove(singleOrder);
    }
    else
    {
        cout << "order can't be deleted because of number limitation of atleast 1!" << endl;
    }


}