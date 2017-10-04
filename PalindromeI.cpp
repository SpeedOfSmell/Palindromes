#include "PalindromeI.hpp"

#include "Data Structures/Queue.hpp"
#include "Data Structures/Stack.hpp"

int PalindromeI::test_string(const std::string& s) {
    int matchLength = 0;

    Queue q = Queue(s.length());
    Stack st;

    for (char c : s) {
        st.push(c);
        q.enqueue(c);
    }

    while (!q.isEmpty()) {
        //std::cout << q.front() << " " << st.top() << std::endl;
        if (q.dequeue() != st.pop()) {
            q.~Queue();
            st.~Stack();
            return matchLength;
        } else {
            matchLength++;
        }
    }

    return -1;
}
