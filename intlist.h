// intlist.h
// Linked list header file 

#ifndef INTLIST_H
#define INTLIST_H

class IntList {

public:

    // constructor and 3 methods already done in intlist.cpp (NO CHANGE):
    IntList();              // constructor
    void print() const;     // print values separate by ' '
 

    // destructor, copy constructor and 6 other METHODS YOU MUST 
    // IMPLEMENT IN intlist.cpp (NO CHANGE HERE):
    ~IntList();                      // destructor
    IntList(const IntList& source); //copy constructor (deep copy)
    int sum() const;                 // sum of all values
    int count() const;               // return count of values
    bool contains(int value) const;  // true if value in list
    int max() const;                 // maximum value
    double average() const;          // average of all values
    void push_front(int value);     // insert value to the front of the list
    void push_back(int value);      // insert value to the back of the list

    IntList& operator=(const IntList& source); //overloaded  (NO CHANGE)

private:

    // (Optional) You can add some private helper functions here.
    

    // definition of Node structure (DO NOT CHANGE):
    struct Node {
        int info;
        Node* next;
    };
    static void clear_nodes(Node *first);
    Node* head; // pointer to head node
    Node* tail; // pointer to the tail node
};

#endif
