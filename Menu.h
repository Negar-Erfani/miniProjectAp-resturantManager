#pragma once
#include <iostream>
#include "linkedlist.h"
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <utility>
using namespace std;

class Menu
{
    private:
    vector <pair<linkedlist*,string>> items;  // غذا، نوشیدنی، پیش غذا

    public:
    void addItem (linkedlist* head,string type);
    void printItem();
    bool isItInMenu(string item);
};