#include <iostream>
using namespace std;

class Queue {
private:
    // Node structure to represent each element in the queue
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}  // Constructor to initialize node
    };

    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to clean up memory
    ~Queue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Enqueue method to insert an element at the rear of the queue
    void enqueue(int val) {
        Node* temp = new Node(val);  // Create a new node with the value
        if (rear == nullptr) {       // Queue is empty
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    // Dequeue method to remove an element from the front of the queue
    void dequeue() {
        if (front == nullptr) {  // Queue is empty
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Element deleted from queue: " << front->data << endl;
        front = front->next;

        if (front == nullptr) {  // If queue becomes empty after dequeue
            rear = nullptr;
        }
        
        delete temp;
    }

    // Display method to show all elements in the queue
    void display() const {
        if (front == nullptr) {  // Queue is empty
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    cout << "Queue Created:" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    cout << "Queue after one deletion:" << endl;
    q.display();

    return 0;
}
