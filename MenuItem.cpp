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
    fstream file(fileName, ios::in | ios::out | ios::app);
    string temp;

    
        if (!file.is_open())
        {
            file.open(fileName, ios::out);
            string userDefinedFood;
            cout << "-----------------------------------------------------------"<<endl;
            cout << "\033[31m"<< "please enter your list for "<< name << ". " << endl;
            cout << "write" << "\033[1m" << "'end' " << "\033[22m" << "when you are done" << "\033[0m :" <<endl;
            while(cin >> userDefinedFood)
            {
                if(userDefinedFood == "end")
                {
                    #ifdef _WIN32
                    system("chcp 65001"); // تنظیم کدپیج UTF-8 در ویندوز
                    #endif
                    cout << "Added successfully \U0001F600" << endl;
                    break;
                }
                else
                {
                    file << userDefinedFood << endl;
                }
            }
            file.close();
        }

    
    file.open(fileName, ios::in | ios::out);
    file.seekp(0, ios::end);
    string temp;
    while (file >> temp) 
    {
        food->insert(temp);
    }
    file.close();
}
