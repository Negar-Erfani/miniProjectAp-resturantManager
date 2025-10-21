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
    ifstream file;
    file.open(fileName);
    string temp;

    
        if (!file.is_open())
        {
            file.close();
            ofstream newFile;
            newFile.open(fileName);
            string userDefinedFood;
            cout << "-----------------------------------------------------------"<<endl;
            cout << "\033[31m"<< "please enter your list for "<< name << ". " << endl;
            cout << "write" << "\033[1m " << "end " << "\033[22m" << "when you are done" << "\033[0m :" <<endl;
            while(cin >> userDefinedFood)
            {
                if(userDefinedFood == "end")
                {
                    #ifdef _WIN32
                    system("chcp 65001 > nul"); 
                    cout << "☺️ " << "\033[32m" << " Added Successfully" << "\033[0m" << endl;
                    #endif
                    break;
                }
                else
                {
                    newFile << userDefinedFood << endl;
                }
            }
            newFile.close();
            file.open(fileName);
        }

    
    string temp2;

    if(file.is_open())
    {
        file.seekg(0, ios::beg);
        while (file >> temp2) 
        {
        food->insert(temp2);
        }
        menu->addItem(food, name);
        file.close();
    }
}

