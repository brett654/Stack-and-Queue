#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    //Add an element to the top of the stack.
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }
    //remove the top element from the stack
    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty, cannot pop." <<std::endl;
            return -1;
        }

        int value = top->data;
        Node* temp = top;

        top = top->next;
        delete temp;
        return value;
    }

    //Peek at the top element
    int peek() const {
        if (isEmpty()) {
            std::cerr << "Stack is empty, cannot pop." <<std::endl;
            return -1;
        }

        return top->data;
    }

    //Determine if the stack is empty.
    bool isEmpty() const {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    //Add an element to the end of the queue.
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (rear) {
            rear->next = newNode;
        }
        else {
            front = newNode;
        }

        rear = newNode;
    }

    //Remove the front element from the queue.
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
        }

        int value = front->data;
        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear == nullptr;
        }

        delete temp;
        return value;
    }

    int peek() const {
        if (isEmpty()) {
            std::cerr << "Queue is empty" << std::endl;
        }

        return front->data;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    // Stack Example
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    std::cout << "Stack top: " << stack.peek() << std::endl; // Should print 30
    std::cout << "Popped: " << stack.pop() << std::endl;     // Should print 30
    std::cout << "Stack top: " << stack.peek() << std::endl; // Should print 20

    // Queue Example
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    std::cout << "Queue front: " << queue.peek() << std::endl; // Should print 10
    std::cout << "Dequeued: " << queue.dequeue() << std::endl;  // Should print 10
    std::cout << "Queue front: " << queue.peek() << std::endl; // Should print 20

    return 0;
}

