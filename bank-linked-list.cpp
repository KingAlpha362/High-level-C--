#include <iostream>
using namespace std;

struct CustomerNode {
    int customerNumber;
    CustomerNode* next;
};

class BankQueue {
private:
    CustomerNode* queueFront;
    CustomerNode* queueRear;
    int customersWaiting;

public:
    BankQueue() {
        queueFront = nullptr;
        queueRear = nullptr;
        customersWaiting = 0;
    }

    bool isEmpty() const {
        return queueFront == nullptr;
    }

    // TASK 1: ENQUEUE (4 MARKS)
    // 1. Create a new node using new.
    // 2. Store customerNumber and set next to nullptr.
    // 3. If empty, set both front and rear to newNode.
    // 4. Otherwise, link rear->next and update rear.
    // 5. Increase customersWaiting.

    void enqueue(int customerNumber) {

        // WRITE YOUR CODE HERE
        CustomerNode* newNode = new CustomerNode;
        newNode->customerNumber = customerNumber;

        newNode->next = nullptr;

        if (isEmpty()) {
            queueFront = newNode;

            queueRear = newNode;
        } else {
            queueRear->next = newNode;

            queueRear = newNode;  // Update queueRear to point to the new last node.
        }
        customersWaiting++;

    }

    // TASK 2: DEQUEUE (4 MARKS)
    // 1. If empty, return -1.
    // 2. Save the front node and customer number.
    // 3. Move queueFront to the next node.
    // 4. If queue becomes empty, reset queueRear.
    // 5. Delete old node.
    // 6. Decrease customersWaiting.
    // 7. Return the customer number.

    int dequeue() {
        // WRITE YOUR CODE HERE
        if (isEmpty()) {
            return -1;
        }
        CustomerNode* nodeToDelete = queueFront;
        int number = nodeToDelete->customerNumber;

        queueFront->next = queueFront;

        if (queueFront == nullptr) {
            queueRear = nullptr;
        }
        delete nodeToDelete;

        customersWaiting--;

        return number;
    }

    // TASK 3: DISPLAY QUEUE (3 MARKS)
    // 1. If empty, display "Queue is empty" and return.
    // 2. Create a temporary pointer at queueFront.
    // 3. Display "Front -> ".
    // 4. Loop until nullptr, displaying each number.
    // 5. Move to the next node each time.
    // 6. Display "<- Rear" at the end.

    void displayQueue() const {

        // WRITE YOUR CODE HERE

        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        CustomerNode* current = queueFront;
        cout << "Front -> ";

        while (current != nullptr) {
            cout << current->customerNumber;
            
            if (current->next != nullptr) {
                cout << " -> ";
            }
            current = current->next;
        }
        cout << " <- Rear" << endl;
    }

    int waiting() const {
        return customersWaiting;
    }

    ~BankQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    BankQueue bankLine;

    bankLine.enqueue(101);
    bankLine.enqueue(102);
    bankLine.enqueue(103);

    bankLine.displayQueue();

    cout << "Served: "
         << bankLine.dequeue() << endl;

    bankLine.displayQueue();

    bankLine.enqueue(104);

    cout << "Waiting: "
         << bankLine.waiting() << endl;

    cout << "Served: "
         << bankLine.dequeue() << endl;

    cout << "Served: "
         << bankLine.dequeue() << endl;

    cout << "Served: "
         << bankLine.dequeue() << endl;

    bankLine.displayQueue();

    if (bankLine.dequeue() == -1) {
        cout << "No customers to serve" << endl;
    }

    return 0;
}
