#include <iostream>
#include "linkedlist.h"
using namespace std;

Node::Node(string value) : data(value), next(nullptr) {};

linkedlist::linkedlist() : head(nullptr) {};
void linkedlist::insert(string value)
{
    Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
}
void linkedlist::remove(string value)
{
    if (head == nullptr) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return;  

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    
}
void linkedlist::display()
{
    Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
}





