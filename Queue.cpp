#include <iostream>
#include <stdexcept>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    size_t count;

public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}
    bool isEmpty() const {
        return count == 0;
    }
    void enqueue(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (isEmpty()) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        ++count;
    }
    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        Node<T>* oldHead = head;
        T value = head->data;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete oldHead;
        --count;
        return value;
    }
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty!");
        }
        return head->data;
    }
    size_t size() const {
        return count;
    }
    void printQueue() const {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }
        Node<T>* current = head;
        std::cout << "Queue elements: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};