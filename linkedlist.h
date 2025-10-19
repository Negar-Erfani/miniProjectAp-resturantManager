#pragma once
#include <iostream>
using namespace std;

struct Node {
    string data;     
    Node* next;   

    Node(string value);
};

class linkedlist
{
    private:
    Node* head;

    public:
    linkedlist();
    void insert(string value);
    void remove(string value);
    void display();
    string asLine();

};