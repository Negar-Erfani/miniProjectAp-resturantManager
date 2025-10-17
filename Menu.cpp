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
        cout << temp.second << ": ";
        temp.first->display();
    }
}
void Menu::addItem (linkedlist* head,string type)
{
    auto temp = make_pair(head,type);
    items.push_back(temp);

}
