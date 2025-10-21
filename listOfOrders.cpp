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

bool listOfOrders::isItOnMenu (Menu* menu, string Item)
{
    return menu->isItInMenu(Item);

}
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
            int size = LineOrder.size();
            for (size_t i = 3; i <= size-2; i++)
            {
                tempLinkedlist->insert(LineOrder.at(i));
            }
            Order order = Order(LineOrder.at(1), stoi(LineOrder.at(2)), tempLinkedlist);
            order.changeStatus(LineOrder.at(LineOrder.size()-1));
            order.orderNum = stoi(LineOrder.at(0));
            orderList->insert(order);
            // order->counter = stoi(LineOrder.at(0));
            LineOrder.clear();
        }
    }
    else
    {
        cout << "LIST failed" << endl;
    }
    orderInfo.close();
}
void listOfOrders::review()
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
                    cout << tempOrder << " ";
                }
                cout << endl;
            }
        }
    }
    else
    {
        cout << "LIST failed" << endl;
    }
    orderInfo.close();
}
void listOfOrders::getOrder(Menu* menu)
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
        cout << "\033[31m" << "Not a studentID. please try again :" << "\033[0m" << endl;
        cin >> studentId;
    }
    cout << "please enter customer's order. write end when you are done :" << endl;
    string temp3;
    cin >> temp3;
    while(temp3=="end")
    {
    cout << "\033[31m" << "You didn't enter any order!" << "\033[0m" << endl;
    cout << "please try again :"<<endl;
    cin >> temp3;
    }
    while(temp3 != "end")
    {
        if(!menu->isItInMenu(temp3))
        {
            cout << "\033[31m" << "This order is not on the menu!" << "\033[0m" << endl;
            delete orderedItems;
            return;

        }
        orderedItems->insert(temp3);
        cin >> temp3;
    }
    Order currentOrder = Order(name, studentId, orderedItems);
    if (orderList == nullptr)
    orderList = new AVLTree();
    orderList->insert(currentOrder);

    ofstream orderInfo("order information.txt", ios::app);
    orderInfo << currentOrder.orderNum << " " << currentOrder.customerName << " " << currentOrder.customerId << " ";
    orderInfo << currentOrder.orderedItems->asLine() << currentOrder.orderStatus << "\n";
    orderInfo.close();
    #ifdef _WIN32
    system("chcp 65001 > nul"); 
    cout << "☺️ " << "\033[32m" << " Added Successfully" << "\033[0m" << endl;
    #endif
    

}
void listOfOrders::deleteOrder(int OrderNum, string singleOrder)
{
    AVLTree::Node* targetOrder = orderList->search(OrderNum);
    // if(targetOrder == nullptr)
    // {
    //     cout << "This order does not exist!" << endl;
    //     return;
    // }
    if(targetOrder->data.orderedItems->getNum() > 1)
    {
        auto check = targetOrder->data.orderedItems->asLine();
        targetOrder->data.orderedItems->remove(singleOrder);
        if (check == targetOrder->data.orderedItems->asLine())
        {
        cout << "\033[31m" << "This order does not exist!" << "\033[0m" << endl;
        }
        else
        {
            // cout << "successfuly removed!" << endl;
            cout << "☺️ " << "\033[32m" << " Removed Successfully" << "\033[0m" << endl;
        }
    }
    else
    {
        cout << "\033[31m"  << "order can't be deleted because of the number limitation of atleast 1!" << "\033[0m" << endl;
    }
    rewriteFile();
    

}
void listOfOrders::changeOrderStatus(int OrderNum, string newStatus)
{
    if (newStatus == "Canceling" || newStatus == "Delivered")
    {
    AVLTree::Node* targetOrder = orderList->search(OrderNum);
    if(targetOrder == nullptr)
    {
        cout << "\033[31m" <<"This order does not exist!" << "\033[0m" << endl;
        return;
    }
    // if(targetOrder->data.orderStatus == "Processing" && newStatus == "Canceling")
    else if(targetOrder->data.orderStatus == "Processing" && newStatus == "Canceling")
    {
    targetOrder->data.orderStatus = newStatus;
    cout << "☺️ " << "\033[32m"<< " Successfuly Canceled!" << endl;
}
else if(targetOrder->data.orderStatus == "Delivered" && newStatus == "Canceling")
{
    cout << "\033[31m"<< "The Order can not be Canceled!" << "\033[0m" << "\033[0m" << endl;
    return;
}
else if(targetOrder->data.orderStatus == "Canceling" && newStatus == "Canceling")
{
    cout << "\033[31m" << "The Order has already been Canceled!" << "\033[0m" << endl;
    return;
}
else if(targetOrder->data.orderStatus == "Processing" && newStatus == "Delivered")
{
    
targetOrder->data.orderStatus = newStatus;
cout << "☺️ " << "\033[32m"<< " Successfuly Delivered!" << "\033[0m" << endl;
}
else if(targetOrder->data.orderStatus == "Delivered" && newStatus == "Delivered")
{
cout << "\033[31m" << "The Order has already been Delivered!" << "\033[0m" << endl;
return;
}
else if(targetOrder->data.orderStatus == "Canceling" && newStatus == "Delivered")
{
cout << "\033[31m" << "The Order has been Canceled!" << "\033[0m" << endl;
return;
}
rewriteFile();
}
else
cout << "\033[31m" << "Failed!" << endl << "You can only enter Delivered or Canceling for a new status of order!" << "\033[0m" << endl;

}
void listOfOrders::addOrder(int OrderNum, string singleOrder, Menu* menu)
{
    AVLTree::Node* targetOrder = orderList->search(OrderNum);
    if(targetOrder == nullptr)
    {
        cout << "\033[31m" << "This order does not exist!" << "\033[0m" << endl;
        return;
    }

    if (targetOrder->data.orderedItems->searchInLinkedlist(singleOrder))
    {
        cout << "\033[31m" << "This order has already exist!" << "\033[0m" << endl;
        return;
    }
    else
    {
        if(!menu->isItInMenu(singleOrder))
        {

            cout << "\033[31m" << "This order is not on the menu!" << "\033[0m" << endl;
            return;
        }
    targetOrder->data.orderedItems->insert(singleOrder);
    cout << "☺️ " << "\033[32m" << " Added Successfully" << "\033[0m" << endl;
    rewriteFile();
    }
    

}
void listOfOrders::replaceOrder(int OrderNum, string oldOrder, string newOrder, Menu* menu)
{
    
    AVLTree::Node* targetOrder = orderList->search(OrderNum);
    if(targetOrder == nullptr)
    {
        cout << "\033[31m" << "This order does not exist!" << "\033[0m" << endl;
        return;
    }
    if(targetOrder->data.orderedItems->searchInLinkedlist(oldOrder))
    {
    if(!menu->isItInMenu(newOrder))
        {

            cout << "\033[31m" << "This order is not on the menu!" << "\033[0m" << endl;
            return;
        }
    targetOrder->data.orderedItems->remove(oldOrder);
    targetOrder->data.orderedItems->insert(newOrder);
    cout << "☺️ " << "\033[32m" << " Added Successfully" << "\033[0m" << "\033[0m" << endl;
    rewriteFile();
    }
    else
    {
        cout << "\033[31m" << "There is no such order to be replaced!" << "\033[0m" << endl;
        return;
    }


}
void listOfOrders::rewriteFile()
{
    vector <AVLTree::Node*> nodes;
    nodes = orderList->inorderNodes(orderList->root);
    ofstream orderInfo("order information.txt", ios::trunc);
    for( AVLTree::Node* it : nodes )
    {
    orderInfo << it->data.orderNum << " " << it->data.customerName << " " << it->data.customerId << " ";
    orderInfo << it->data.orderedItems->asLine() << it->data.orderStatus << "\n";
    }
    orderInfo.close();

}