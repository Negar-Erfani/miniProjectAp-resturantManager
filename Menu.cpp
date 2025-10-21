#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include "Menu.h"
#include "linkedlist.h"
#include <utility>
using namespace std;

void Menu::printItem()
{
    for (const auto& temp : items)
    {
        cout << "\033[36m" << temp.second << ": " << "\033[0m";
        temp.first->display();
    }
}
void Menu::addItem (linkedlist* head,string type)
{
    auto temp = make_pair(head,type);
    items.push_back(temp);

}
bool Menu::isItInMenu(string item)
{
    bool exist = 0;
    for (const auto& temp : items)
    {
        exist = temp.first->searchInLinkedlist(item);
        if(exist)
        {
            return exist;
        }
        
    }
    return exist;
    
}