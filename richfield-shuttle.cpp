#include <iostream>
using namespace std;

struct TicketNode {
    int ticketNumber;
    TicketNode* next;
};

class CinemaQueue {
private:
    TicketNode* front;
    TicketNode* rear;
    int ticketCount;

public:
    CinemaQueue() {
        front = nullptr;
        rear = nullptr;
        ticketCount = 0;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    // TASK 1: ENQUEUE (4 MARKS)
    // 1. Create a new node using new.
    // 2. Store ticketNumber in the node.
    // 3. Set the new node's next to nullptr.
    // 4. If empty, make front and rear point to newNode.
    // 5. Otherwise, connect the old rear to newNode.
    //    Then update rear.
    // 6. Increase ticketCount.

    void enqueue(int ticketNumber) {
        // WRITE YOUR CODE HERE
        TicketNode* newNode = new TicketNode;
        newNode->ticketNumber = ticketNumber;

        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;

            rear = newNode;
        }
        ticketCount++;

    }

    // TASK 2: DEQUEUE (4 MARKS)
    // 1. Check if the queue is empty.
    //    If empty, return -1.
    // 2. Save the front node in a temporary pointer.
    // 3. Save the ticket number before deleting.
    // 4. Move front to the next node.
    // 5. If the queue becomes empty, set rear to nullptr.
    // 6. Delete the old front node.
    // 7. Decrease ticketCount.
    // 8. Return the removed ticket number.

    int dequeue() {
        // WRITE YOUR CODE HERE
        if (isEmpty()) {
            return -1;
        }
        TicketNode* temp = front;
        int savedTicket = temp->ticketNumber;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;

        ticketCount--;
        return savedTicket;


    }

    // TASK 3: DISPLAY QUEUE (3 MARKS)
    // 1. If empty, display "Queue is empty" and return.
    // 2. Create a temporary pointer starting at front.
    // 3. Display "Front -> ".
    // 4. Use a while loop to visit every node.
    // 5. Display each ticket number.
    // 6. Move the pointer to the next node.
    // 7. Display "<- Rear" at the end.

    void displayQueue() const {
        // WRITE YOUR CODE HERE
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        TicketNode* current = front;
        cout << "Front -> " << endl;

        while (current != nullptr) {
            cout << current->ticketNumber;

            if (current->next != nullptr) {
                cout << " -> " << endl;
            }
            current = current->next;
        }
        cout << " <- Rear" << endl;
    }

    int waiting() const {
        return ticketCount;
    }

    ~CinemaQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    CinemaQueue cinemaLine;

    cinemaLine.enqueue(501);
    cinemaLine.enqueue(502);
    cinemaLine.enqueue(503);
    cinemaLine.enqueue(504);

    cinemaLine.displayQueue();

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cinemaLine.displayQueue();

    cinemaLine.enqueue(505);
    cinemaLine.enqueue(506);

    cout << "Customers waiting: "
         << cinemaLine.waiting() << endl;

    cinemaLine.displayQueue();

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cinemaLine.displayQueue();

    if (cinemaLine.dequeue() == -1) {
        cout << "No tickets to serve" << endl;
    }

    cinemaLine.enqueue(507);
    cinemaLine.displayQueue();

    return 0;
}
