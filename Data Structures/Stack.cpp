#include "Stack.hpp"

#include <iostream>

Stack::~Stack() {
    linkedlist.~LinkedList();
}

/*****************
Operator overloads
*****************/
Stack& Stack::operator=(const Stack& right) {
    linkedlist = right.getList();
    return *this;
}

/***************
Member Functions
**************/
//pre:
//post: return the underlying linkedlist
LinkedList Stack::getList() const {
    return linkedlist;
}

//pre:
//post: return the top char in the stack
char Stack::top() const {
    return linkedlist.getEnd()->value;
}

//pre:
//post: append the object to the end of the list
void Stack::push(char val) {
    linkedlist.appendNode(val);
}

//pre:
//post: remove the last entry in the vector and return the value
char Stack::pop() {
    ListNode* h = linkedlist.getHead();
    if(h) {
        char val = linkedlist.getEnd()->value;
        linkedlist.deleteNode();
        return val;
    }

    return ' ';
}
