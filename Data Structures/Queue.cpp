#include "Queue.hpp"

Queue::Queue(int size) {
    queueArray = new char[size];
    queueSize = size;
    f = 0;
    r = 0;
    numItems = 0;
}

Queue::Queue(const Queue& obj) {
    if (obj.queueSize > 0)
        queueArray = new char[obj.queueSize];
    else queueArray = nullptr;

    queueSize = obj.queueSize;
    f = obj.f;
    r = obj.r;
    numItems = obj.numItems;

    for (int count = 0; count < obj.queueSize; count++)
        queueArray[count] = obj.queueArray[count];
}

Queue::~Queue() {
    if (numItems > 0)
        delete [] queueArray;
}

void Queue::enqueue(char item) {
    if (numItems < queueSize){
        queueArray[r] = item;
        r = (r + 1) % queueSize;
        numItems++;
    }
}

char Queue::dequeue() {
    if (isEmpty())
        throw "The queue is empty.\n";
    else {
        char item = queueArray[f];
        f = (f + 1) % queueSize;
        numItems--;
        return item;
    }
}

char Queue::front() const {
    if (isEmpty())
        throw "The queue is empty.\n";
    else return queueArray[f];
}

bool Queue::isEmpty() const {
    if (numItems <= 0) return true;
    return false;
}
