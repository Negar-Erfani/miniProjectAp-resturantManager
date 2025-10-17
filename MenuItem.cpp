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

MenuItem::MenuItem (string name, Menu* menu) : name(name)
{
    string fileName = name+".txt";
    food = new linkedlist();
    ifstream file(fileName);
    string temp;
    if (file.is_open())
    {
        while(file >> temp)
        {
            ofstream file(fileName);
            food->insert(temp);
        }
        file.close();

    }
    else
    {
    fstream file(fileName, ios::out | ios::app);
    if (file.is_open())
    {
        string userDefinedFood;
        while(cin >> userDefinedFood)
        {
            if(userDefinedFood == "end")
            {
                break;
            }
            else
            {
                file << userDefinedFood << endl;
            }

        }

    }
    }
    menu->addItem (food, name);

}
