#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
#include "Menu.h"
#include "linkedlist.h"
#include <utility>
using namespace std;

void MenuItems::printItem()
{
    for (const auto& temp : items)
    {
        cout << temp.second << ": ";
        temp.first->display();
    }
}
