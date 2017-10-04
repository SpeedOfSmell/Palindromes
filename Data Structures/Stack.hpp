// Vlad Mirea vm63@zips.uakron.edu

#ifndef STACK_HPP
#define STACK_HPP

#include "Data Structures\LinkedList.hpp"

class Stack {
    public:
        Stack() : linkedlist(LinkedList()){} // default constructor
        Stack(const Stack& st) : linkedlist(st.getList()){} //copy constructor
        ~Stack();

        Stack& operator=(const Stack&); //copy assignment

        char top() const;
        LinkedList getList() const;

        void push(char);
        char pop();

    private:
        LinkedList linkedlist;
};


#endif
