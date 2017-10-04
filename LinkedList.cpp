#include "Data Structures/LinkedList.hpp"

#include <iostream>

//**************************************************
// Constructor                                     *
// Initializes the head                            *
// pre: n/a                                        *
// post: head pointing to null                     *
//**************************************************
LinkedList::LinkedList() {
    head = nullptr;
}

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
// pre: n/a                                        *
// post: destroyed object                          *
//**************************************************
LinkedList::~LinkedList()
{
   ListNode *nodePtr;   // To traverse the list
   ListNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
   nodePtr = head;

   // While nodePtr is not at the end of the list...
   while (nodePtr != nullptr)
   {
      // Save a pointer to the next node.
      nextNode = nodePtr->next;

      // Delete the current node.
      delete nodePtr;

      // Position nodePtr at the next node.
      nodePtr = nextNode;
   }

}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
// pre: an empty parameter list                    *
// post: standard output of the linked list        *
//**************************************************
void LinkedList::displayList() const
{

   ListNode *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
   nodePtr = head;
   if (head) { //If there is anything in the list
        std::cout << "[" << nodePtr->value << "]"; //Display the first value
        nodePtr = nodePtr->next; //Move on to the next one

        while (nodePtr) { //While the ptr still hasn't reached the end
            // Display the value in this node.
            std::cout << " --> [" << nodePtr->value << "]";
            // Move to the next node.
            nodePtr = nodePtr->next;
        }
   }

   std::cout << std::endl;

}

//**************************************************
// appendNode                                      *
// Creates a new node and appends it to the end    *
// of the list.                                    *
// pre: value of new node                          *
// post: list with new node at the end             *
//**************************************************
void LinkedList::appendNode(char value) {
    ListNode *newNode = new ListNode(); //Create new node to append
    newNode->value = value; //Set the new node's value using the passed char
    newNode->next = nullptr; //Since this will be at the end, it will point to null;

    if (!head)  //If there is no head node yet (usually means this is the first node)
        head = newNode; //The head will point to this new node, making it first in the list
    else //Otherwise, insert newNode at the end
        getEnd()->next = newNode; //Have previous last node point to new node, making new node last

}

//**************************************************
// insertNode                                      *
// Creates a new node and inserts it in            *
// descending order                                *
// pre: value of new node                          *
// post: list with new node inserted               *
//**************************************************
void LinkedList::insertNode(char value) {
    ListNode *insertLocation;
    ListNode *newNode = new ListNode(); //Create new node to append

    newNode->value = value; //Set the new node's value using the passed char

    insertLocation = findInsertSpot(value);
    if(!head) {  //If there is no head node yet (usually means this is the first node)
        head = newNode; //Point the head at the new node
        newNode->next = nullptr;
    } else if (insertLocation == nullptr) { //If new node should be first
        newNode->next = head; //Point the new node at the previous first node
        head = newNode; //Point the head at the new node
    } else {
        newNode->next = insertLocation->next;
        insertLocation->next = newNode;
    }

}

//**************************************************
// deleteNode                                      *
// Deletes the node with the value passed          *
// pre: value of node to delete                    *
// post: list with deleted node                    *
//**************************************************
void LinkedList::deleteNode(char value) {
    ListNode *nodePtr = head; //Used to transverse the list
    ListNode *trailingPtr;

    if (nodePtr->value == value) { //Check if first node
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        while (nodePtr != nullptr && nodePtr->value != value) {
            trailingPtr = nodePtr;
            nodePtr = nodePtr->next; //Move on to the next one
        }

        if (nodePtr) {
            trailingPtr->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//**************************************************
// getEnd                                          *
// Returns pointer to last node in list            *
// pre: an empty parameter list                    *
// post: pointer to last node in list              *
//**************************************************
LinkedList::ListNode * LinkedList::getEnd() {
    ListNode *nodePtr = head;
    while (nodePtr->next) //Find the last node in the list
        nodePtr = nodePtr->next; //Move on to the next one

    return nodePtr; //Return last node
}

//**************************************************
// findInsertSpot                                  *
// Find where the value belongs in descending order*
// pre: value of node                              *
// post: pointer to node in front of where node    *
// belongs                                         *
//**************************************************
LinkedList::ListNode * LinkedList::findInsertSpot(char value) {
    using std::tolower;
    using std::isalpha;

    ListNode *nodePtr = head; //Used to transverse the list
    ListNode *trailingPtr;

    value = tolower(value);

    if(value > tolower(head->value)) { //Check if new node belongs as first node
        trailingPtr = nullptr;
    }else {
        while (nodePtr != nullptr && tolower(nodePtr->value) > value) { //Find the last node in the list
            trailingPtr = nodePtr;
            nodePtr = nodePtr->next; //Move on to the next one
        }
    }

    return trailingPtr; //Return last node
}
