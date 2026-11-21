#include <iostream>
using namespace std;

struct CustomerNode {
    int customerNumber;
    CustomerNode* next; // Points to the next customer in line.
};

class BankQueue {
private:
    CustomerNode* queueFront;
    CustomerNode* queueRear;
    int customersWaiting;

public:
    BankQueue() {
        // 1. Start with no front or rear node and zero customers waiting.
        queueFront = nullptr;
        queueRear = nullptr;
        customersWaiting = 0;
    }

    bool isEmpty() const {
        // 1. A null front pointer means nobody is waiting.
        return queueFront == nullptr;
    }

    // Task 1 (4 marks) adds a customer to the back of the queue.
    void enqueue(int customerNumber) {

        // 1. new CustomerNode creates the node and newNode stores its address.
        CustomerNode* newNode = new CustomerNode;
        // 2. Store the customer number in the new node.
        newNode->customerNumber = customerNumber;

        newNode->next = nullptr; // No customer follows the new last node.

        // 3. In an empty queue, the new customer is both first and last.
        if (isEmpty()) {
            queueFront = newNode;

            queueRear = newNode;
        } else {
            // 4. Link the new node after the old rear, then update queueRear.
            queueRear->next = newNode;

            queueRear = newNode;
        }
        // 5. Increase the number of customers waiting.
        customersWaiting++;

    }

    // Task 2 (4 marks) is meant to remove and return the first customer number.
    int dequeue() {
        // 1. Return -1 if there is no customer to serve.
        if (isEmpty()) {
            return -1;
        }
        // 2. Save the front node and copy its customer number before deletion.
        CustomerNode* nodeToDelete = queueFront;
        int number = nodeToDelete->customerNumber;

        // 3. The front should advance here. This line makes the node link to itself.
        queueFront->next = queueFront;

        // 4. A null front pointer would mean the rear should also be cleared.
        if (queueFront == nullptr) {
            queueRear = nullptr;
        }
        // 5. Free the old front node and reduce the customer count.
        delete nodeToDelete; // queueFront still points to this node when it is freed.

        customersWaiting--;

        // 6. Return the customer number saved in step 2.
        return number;
    }

    // Task 3 (3 marks) displays the customer numbers from front to rear.
    void displayQueue() const {

        // 1. Print the empty-queue message and return if there are no customers.
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        // 2. Start a temporary pointer at queueFront and print the opening label.
        CustomerNode* current = queueFront;
        cout << "Front -> ";

        // 3. Print each customer number and follow next until the queue ends.
        while (current != nullptr) {
            cout << current->customerNumber;
            
            if (current->next != nullptr) { // Print a separator if a customer follows.
                cout << " -> ";
            }
            current = current->next;
        }
        // 4. Show the rear label to end the display.
        cout << " <- Rear" << endl;
    }

    int waiting() const {
        // 1. Return the customer count maintained by enqueue and dequeue.
        return customersWaiting;
    }

    ~BankQueue() {
        // 1. Keep calling dequeue to clean up while the front pointer is set.
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    // 1. Create a queue, add three customers, and display their order.
    BankQueue bankLine;

    bankLine.enqueue(101);
    bankLine.enqueue(102);
    bankLine.enqueue(103);

    bankLine.displayQueue();

    // 2. Test serving the first customer and display the queue again.
    cout << "Served: "
         << bankLine.dequeue() << endl;

    bankLine.displayQueue();

    // 3. Add another customer and show the number waiting.
    bankLine.enqueue(104);

    cout << "Waiting: "
         << bankLine.waiting() << endl;

    // 4. Test serving three more customers.
    cout << "Served: "
         << bankLine.dequeue() << endl;

    cout << "Served: "
         << bankLine.dequeue() << endl;

    cout << "Served: "
         << bankLine.dequeue() << endl;

    bankLine.displayQueue();

    // 5. Check for -1, the empty-queue result.
    if (bankLine.dequeue() == -1) {
        cout << "No customers to serve" << endl;
    }

    return 0;
}
