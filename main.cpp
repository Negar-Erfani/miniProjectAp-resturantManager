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

int main() {
    // از روی فایل لینک لیست مربوط به هر کدوم رو پر کن
    Menu* menu = new Menu();
    MenuItem* food = new MenuItem("food", menu);
    MenuItem* apetizer = new MenuItem("apetizer", menu);
    MenuItem* drink = new MenuItem("drink", menu);
    menu->printItem();


    return 0;
}