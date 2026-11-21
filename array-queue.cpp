#include <iostream>
using namespace std;

// The queue can store up to five integers.
const int MAX_SIZE = 5;

class IntQueue {
private:
    // Count the stored items and identify the next free index when there is room.
    int itemCount;

    // Store the integers in a fixed-size array.
    int items[MAX_SIZE];

public:
    IntQueue() {
        // 1. Start with zero items in the queue.
        itemCount = 0;
    }

    bool isEmpty() const {
        // 1. Check whether the queue contains zero items.
        return itemCount == 0;
    }

    bool isFull() const {
        // 1. Check whether the count has reached the array capacity.
        return itemCount == MAX_SIZE;
    }

    void enqueue(int newItem) {
        // 1. Print a message if there are no free slots.
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            // 2. Store the item after the current last item.
            items[itemCount] = newItem;

            // 3. Count the added item and advance the next free index.
            itemCount++;
        }
    }

    void dequeue() {
        // 1. Print a message if there is nothing to remove.
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            // 2. Shift any later items left to fill the old front slot.
            for (int index = 0; index < itemCount - 1; index++) {
                items[index] = items[index + 1]; // Copy the item from the next slot.
            }

            // 3. Reduce the count so the old last slot is outside the queue.
            itemCount--;
        }
    }

    int front() const {
        // 1. Read the first slot. This requires at least one item in the queue.
        return items[0];
    }
};

int main() {
    // 1. Enqueue 10, 20, and 30 and show that 10 is at the front.
    IntQueue numberQueue;

    numberQueue.enqueue(10);
    numberQueue.enqueue(20);
    numberQueue.enqueue(30);

    cout << "Front: " << numberQueue.front() << endl;

    // 2. Remove 10 and show that 20 is now at the front.
    numberQueue.dequeue();
    cout << "Front: " << numberQueue.front() << endl;

    // 3. Remove 20 and 30, then try a removal from the empty queue.
    numberQueue.dequeue();
    numberQueue.dequeue();
    numberQueue.dequeue();

    if (numberQueue.isEmpty())
        cout << "Queue is now empty" << endl;

    // 4. Fill all five slots, try adding a sixth item, and read the front again.
    for (int number = 1; number <= 6; number++)
        numberQueue.enqueue(number);

    cout << "Front: " << numberQueue.front() << endl;

    return 0;
}