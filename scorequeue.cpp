#include <iostream>

using namespace std;

const int MAX_SIZE = 4;

class ScoreQueue {
private:
    int itemCount; // Counts scores and gives the next free index when there is room.
    int items[MAX_SIZE];

public:
    ScoreQueue() {
        // 1. Start with zero scores in the queue.
        itemCount = 0;
    }

    bool isEmpty() const {
        // 1. Check whether the score count is zero.
        return itemCount == 0;
    }

    bool isFull() const {
        // 1. Check whether all the available slots are in use.
        return itemCount == MAX_SIZE;
    }

    void enqueue(int score) {
        // 1. Print a message if the queue has no free slots.
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            // 2. Write the score at the next free index.
            items[itemCount] = score;

            // 3. Count the new score and advance the index.
            itemCount++;
        }
    }

    void dequeue() {
        // 1. This guard blocks removal when the queue is full.
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            // 2. Copy each later score one slot left to replace the front score.
            for (int index = 0; index < itemCount - 1; index++) {
                items[index] = items[index + 1];
            }

            // 3. Reduce the count. This can make it negative if the queue is empty.
            itemCount--;
        }
    }

    int front() const {
            // 1. Read the score at index 0. This requires at least one stored score.
            return items[0];
        }
};

int main() {
    // 1. Add three scores and show the first one added.
    ScoreQueue scores;

    scores.enqueue(45);
    scores.enqueue(60);
    scores.enqueue(75);
    cout << "Front score: " << scores.front() << endl;

    // 2. Remove the front score and show its replacement.
    scores.dequeue();
    cout << "Front score: " << scores.front() << endl;

    // 3. Fill the two remaining slots and try adding one more score.
    scores.enqueue(80);
    scores.enqueue(95);
    scores.enqueue(100);

    if (scores.isFull())
        cout << "All spaces used" << endl;

    cout << "Front score: " << scores.front() << endl;

    // 4. Try five removals. The full-queue check blocks each one.
    for (int count = 0; count < 5; count++)
        scores.dequeue();

    // 5. Check whether the scores have been cleared.
    if (scores.isEmpty())
        cout << "No scores left" << endl;

    return 0;
}