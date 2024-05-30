#pragma once

#include <algorithm>
#include "Shared.h"
#include "Node.h"

class LinkedList {
private:
    Node *head, *tail;

    void SortString(string &s)
    {
        sort(s.begin(), s.end());
    }

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    Node* getHead()
    {
        return this->head;
    }

    Node* getTail()
    {
        return this->tail;
    }

    void AddNode(string s)
    {
        Node *tmp = new Node();
        tmp->data = s;
        tmp->next = nullptr;

        if (head == nullptr) {
            head = tmp;
            tail = tmp;
        } 
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }    

    void Print()
    {
        Node *tmp;
        tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << endl;
            tmp = tmp->next;
        }
    }

    void PrintCycles()
    {
        Node *tmp;
        tmp = head;
        while (tmp != nullptr) {
            cout << tmp->data << tmp->data[0] << endl;
            tmp = tmp->next;
        }
    }

    bool Exists(string s)
    {
        Node *tmp;
        tmp = head;
        bool result = false;
        string tmpString; 
        while (tmp != nullptr && result == false) {
            tmpString = tmp->data;
            SortString(tmpString);
            SortString(s);
            if (tmpString == s) {
                result = true;
            }
            tmp = tmp->next;
        }
        return (result);
    }
};