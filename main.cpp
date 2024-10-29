/*
 * main.cpp
 *
 *  Created on: Oct 28, 2024
 *      Author: Yohanna Diaz Florian
 */

#include <iostream>
#include <string>

using namespace std;

class Element {
public:
    string name;
    Element* next;

    Element(string name) : name(name), next(nullptr) {}
};

class LinkedList {
public:
    Element* head;

    LinkedList() : head(nullptr) {}

    void Add(Element* newElement) {
        if (head == nullptr) {
            head = newElement;
        } else {
            Element* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newElement;
        }
    }

    Element* GetFirst() {
        return head;
    }

    void Remove(string name) {
        if (head == nullptr) return;

        if (head->name == name) {
            Element* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Element* temp = head;
        while (temp->next != nullptr && temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next != nullptr) {
            Element* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }

    void Modify(int position, string newName) {
        Element* temp = head;
        int index = 0;

        while (temp != nullptr && index < position) {
            temp = temp->next;
            index++;
        }

        if (temp != nullptr) {
            temp->name = newName;
        }
    }
};

int main() {
    Element one("one");
    Element two("two");
    Element three("three");
    Element four("four");

    LinkedList list;
    list.Add(&one);
    list.Add(&two);
    list.Add(&three);

    Element* i = list.GetFirst();
    while (i != nullptr) {
        cout << i->name << endl;
        i = i->next;
    }

    list.Remove("two");
    list.Modify(1, "four");

    cout << "\nAfter removing and modifying:\n";

    i = list.GetFirst();
    while (i != nullptr) {
        cout << i->name << endl;
        i = i->next;
    }

    return 0;
}
