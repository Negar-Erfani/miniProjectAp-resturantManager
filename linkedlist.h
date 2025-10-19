#pragma once
#include <iostream>
using namespace std;

struct Nodel {
    string data;     
    Nodel* next;   

    Nodel(string value);
};

class linkedlist
{
    private:
    Nodel* head;

    public:
    linkedlist();
    void insert(string value);
    void remove(string value);
    void display();
    string asLine();
    int getNum();

};