#include <iostream>
using namespace std;

struct TicketNode {
    int ticketNumber;
    TicketNode* next; // Points to the next ticket in the queue.
};

class CinemaQueue {
private:
    TicketNode* front;
    TicketNode* rear;
    int ticketCount;

public:
    CinemaQueue() {
        // 1. Start with no front or rear node and zero tickets.
        front = nullptr;
        rear = nullptr;
        ticketCount = 0;
    }

    bool isEmpty() const {
        // 1. A null front pointer means there are no tickets waiting.
        return front == nullptr;
    }

    // Task 1 (4 marks) adds a ticket to the rear of the queue.
    void enqueue(int ticketNumber) {
        // 1. new TicketNode creates the node and newNode stores its address.
        TicketNode* newNode = new TicketNode;
        // 2. Store the ticket number in the new node.
        newNode->ticketNumber = ticketNumber;

        newNode->next = nullptr; // No ticket follows the new last node.

        // 3. In an empty queue, the new node is both first and last.
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            // 4. Link the old rear node to the new one, then update rear.
            rear->next = newNode;

            rear = newNode;
        }
        // 5. Add one to the number of tickets waiting.
        ticketCount++;

    }

    // Task 2 (4 marks) removes and returns the first ticket number.
    int dequeue() {
        // 1. Return -1 if there is no ticket to serve.
        if (isEmpty()) {
            return -1;
        }
        // 2. Save the old front node and copy its ticket number before deletion.
        TicketNode* temp = front;
        int savedTicket = temp->ticketNumber;

        // 3. Move front to the next ticket.
        front = front->next;

        // 4. Clear rear too if the queue has become empty.
        if (front == nullptr) {
            rear = nullptr;
        }
        // 5. Free the old front node and reduce the ticket count.
        delete temp;

        ticketCount--;
        // 6. Return the ticket number saved in step 2.
        return savedTicket;


    }

    // Task 3 (3 marks) displays the tickets from front to rear.
    void displayQueue() const {
        // 1. Print the empty-queue message and return if there are no tickets.
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        // 2. Start a temporary pointer at front and print the opening label.
        TicketNode* current = front;
        cout << "Front -> " << endl;

        // 3. Print each ticket number and follow next until the queue ends.
        while (current != nullptr) {
            cout << current->ticketNumber;

            if (current->next != nullptr) { // Add a separator before the next ticket.
                cout << " -> " << endl;
            }
            current = current->next;
        }
        // 4. Print the rear label to finish the display.
        cout << " <- Rear" << endl;
    }

    int waiting() const {
        // 1. Return the count maintained by enqueue and dequeue.
        return ticketCount;
    }

    ~CinemaQueue() {
        // 1. Remove and free each remaining node when the queue is destroyed.
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    // 1. Start a queue, add four tickets, and show their order.
    CinemaQueue cinemaLine;

    cinemaLine.enqueue(501);
    cinemaLine.enqueue(502);
    cinemaLine.enqueue(503);
    cinemaLine.enqueue(504);

    cinemaLine.displayQueue();

    // 2. Serve the first two tickets and display the queue again.
    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cinemaLine.displayQueue();

    // 3. Add two more tickets and show how many customers are waiting.
    cinemaLine.enqueue(505);
    cinemaLine.enqueue(506);

    cout << "Customers waiting: "
         << cinemaLine.waiting() << endl;

    cinemaLine.displayQueue();

    // 4. Serve the remaining tickets and display the empty queue.
    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cout << "Ticket served: "
         << cinemaLine.dequeue() << endl;

    cinemaLine.displayQueue();

    // 5. Try serving a ticket from the empty queue.
    if (cinemaLine.dequeue() == -1) {
        cout << "No tickets to serve" << endl;
    }

    // 6. Add a ticket again to test reusing the empty queue.
    cinemaLine.enqueue(507);
    cinemaLine.displayQueue();

    return 0;
}
