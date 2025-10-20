#include <iostream>
#include "linkedlist.h"
using namespace std;

Nodel::Nodel(string value) : data(value), next(nullptr) {};

linkedlist::linkedlist() : head(nullptr) {};
void linkedlist::insert(string value)
{
    Nodel* newNode = new Nodel(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Nodel* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
}
void linkedlist::remove(string value)
{
    if (head == nullptr) return;

        if (head->data == value) {
            Nodel* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Nodel* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return;  

        Nodel* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    
}
void linkedlist::display()
{
    Nodel* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
}
int linkedlist::getNum()
{
        int number = 0;
        Nodel* temp = head;
        if(temp == 0)
        {
            return 0;
        }
        while (temp != nullptr) 
        {
            number++;
            temp = temp->next;
        }
        return number;
}
string linkedlist::asLine()
{
    Nodel* temp = head;
    string tempLine;
        while (temp != nullptr) {
            tempLine += temp->data;
            tempLine += " ";
            temp = temp->next;
        }
        return tempLine;
}






