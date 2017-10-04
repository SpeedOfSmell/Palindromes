#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

struct ListNode{
    char value;
    ListNode *next;
};

class LinkedList
{
    private:
        ListNode* head;
        ListNode* findInsertSpot(char);

    public:
        LinkedList();
        ~LinkedList();
        ListNode* getHead() const {return head;}
        ListNode* getEnd() const;
        void displayList() const;
        void appendNode(char);
        void insertNode(char);
        void deleteNode();
};

#endif // LINKEDLIST_HPP
