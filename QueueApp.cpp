#include <iostream>
#include "Queue.cpp"

int main() {
    Queue<int> q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Print the queue
    q.printQueue();

    // Display size and front element
    std::cout << "Queue size: " << q.size() << std::endl;
    std::cout << "Front element: " << q.peek() << std::endl;

    // Dequeue element
    std::cout << "Dequeued: " << q.dequeue() << std::endl;

    // Print the queue after dequeueing
    q.printQueue();

    // Check remaining elements
    std::cout << "Queue size after dequeuing: " << q.size() << std::endl;
    std::cout << "Front element after dequeuing: " << q.peek() << std::endl;

    // Dequeue the last element
    q.dequeue();

    // Check if the queue is empty
    std::cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}