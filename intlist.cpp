// intlist.cpp
// Implements class IntList
// Zayan Khan — 20 Apr 2025

#include "intlist.h"
#include <iostream>
using std::cout;



void IntList::clear_nodes(IntList::Node* first)         
{
    while (first) {
        IntList::Node* tmp = first->next;               
        delete first;
        first = tmp;
    }
}

IntList::IntList() : head(nullptr), tail(nullptr) { }

IntList::IntList(const IntList& src) : head(nullptr), tail(nullptr)
{
    for (Node* n = src.head; n; n = n->next)
        push_back(n->info);                  
}

IntList::~IntList()
{
    clear_nodes(head);
    head = tail = nullptr;
}


IntList& IntList::operator=(const IntList& src)
{
    if (this == &src) return *this;          

    clear_nodes(head);
    head = tail = nullptr;

    for (Node* n = src.head; n; n = n->next)
        push_back(n->info);

    return *this;
}


int IntList::count() const
{
    int c = 0;
    for (Node* n = head; n; n = n->next) ++c;
    return c;
}

int IntList::sum() const
{
    int total = 0;
    for (Node* n = head; n; n = n->next) total += n->info;
    return total;
}

bool IntList::contains(int value) const
{
    for (Node* n = head; n; n = n->next)
        if (n->info == value) return true;
    return false;
}

int IntList::max() const
{
    if (!head) return 0;
    int m = head->info;
    for (Node* n = head->next; n; n = n->next)
        if (n->info > m) m = n->info;
    return m;
}

double IntList::average() const
{
    int n = count();
    return n ? static_cast<double>(sum()) / n : 0.0;
}

void IntList::push_front(int value)
{
    Node* n = new Node{value, head};
    head = n;
    if (!tail) tail = head;                  
}

void IntList::push_back(int value)
{
    Node* n = new Node{value, nullptr};
    if (!tail) {
        head = tail = n;                 
    } else {
        tail->next = n;
        tail = n;
    }
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

