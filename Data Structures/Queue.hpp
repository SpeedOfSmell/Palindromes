#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

class Queue {
    private:
        char* queueArray;
        int queueSize;
        int numItems;

        int f;
        int r;

    public:
        Queue() = default;
        Queue(int);
        Queue(const Queue&);
        ~Queue();

        void enqueue(char);
        char dequeue();
        char front() const;
        bool isEmpty() const;
        int getSize() const;
};

#endif // QUEUE_HPP_INCLUDED
