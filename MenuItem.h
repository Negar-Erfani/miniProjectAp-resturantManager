#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
#include "linkedlist.h"
#include "Menu.h"
using namespace std;

class MenuItem
{
    private:
    linkedlist* food;

    public:
    MenuItem(string name, Menu menu);
    string name;
    
};