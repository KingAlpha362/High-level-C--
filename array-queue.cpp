#include <iostream>
using namespace std;

// The queue can store up to five integers.
const int MAX_SIZE = 5;

class IntQueue {
private:
    // 1. Count how many items are currently stored.
    int itemCount;

    // Store the integers in a fixed-size array.
    int items[MAX_SIZE];

public:
    // 1. Constructor: a new queue starts empty.
    IntQueue() {
        itemCount = 0;
    }

    // 2. The queue is empty when its item count is zero.
    bool isEmpty() const {
        return itemCount == 0;
    }

    // The queue is full when all five positions are used.
    bool isFull() const {
        return itemCount == MAX_SIZE;
    }

    // 3. Add an item at the rear of the queue.
    void enqueue(int newItem) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            // itemCount identifies the next free array position.
            items[itemCount] = newItem;

            // Record that the queue contains one more item.
            itemCount++;
        }
    }

    // 4. Remove the item at the front of the queue.
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            // Move each remaining item one position left.
            // For example: 10, 20, 30 becomes 20, 30.
            for (int index = 0; index < itemCount - 1; index++) {
                items[index] = items[index + 1];
            }

            // The queue now contains one fewer item.
            itemCount--;
        }
    }

    // 5. Read the front item without removing it.
    // Only call this function when the queue is not empty.
    int front() const {
        return items[0];
    }
};

// 6. Test the queue.
int main() {
    IntQueue numberQueue;

    // Add three integers: front to rear is 10, 20, 30.
    numberQueue.enqueue(10);
    numberQueue.enqueue(20);
    numberQueue.enqueue(30);

    // The first integer added is at the front.
    cout << "Front: " << numberQueue.front() << endl;

    // Remove 10. The front is now 20.
    numberQueue.dequeue();
    cout << "Front: " << numberQueue.front() << endl;

    // Remove 20 and 30, then attempt removal from an empty queue.
    numberQueue.dequeue();
    numberQueue.dequeue();
    numberQueue.dequeue();

    if (numberQueue.isEmpty())
        cout << "Queue is now empty" << endl;

    // Store 1 through 5. The attempt to add 6 fails.
    for (int number = 1; number <= 6; number++)
        numberQueue.enqueue(number);

    // The first integer added, 1, is still at the front.
    cout << "Front: " << numberQueue.front() << endl;

    return 0;
}