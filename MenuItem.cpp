#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
#include "linkedlist.h"
#include "Menu.h"
#include "MenuItem.h"
using namespace std;

MenuItem::MenuItem (string name, Menu menu) : name(name)
{
    food = new linkedlist();
    menu.addItem (food, name);
}
