#include <iostream>

using namespace std;

const int MAX_SIZE = 4;

class ScoreQueue {
private:
    int itemCount;
    int items[MAX_SIZE];

public:
    ScoreQueue() {
        itemCount = 0;
    }

    bool isEmpty() const {
        return itemCount == 0;
    }

    bool isFull() const {
        return itemCount == MAX_SIZE;
    }

    void enqueue(int score) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            items[itemCount] = score;

            itemCount++;
        }
    }

    void dequeue() {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            for (int index = 0; index < itemCount - 1; index++) {
                items[index] = items[index + 1];
            }

            itemCount--;
        }
    }

    int front() const {
            return items[0];
        }
};

int main() {
    ScoreQueue scores;

    scores.enqueue(45);
    scores.enqueue(60);
    scores.enqueue(75);
    cout << "Front score: " << scores.front() << endl;

    scores.dequeue();
    cout << "Front score: " << scores.front() << endl;

    scores.enqueue(80);
    scores.enqueue(95);
    scores.enqueue(100);

    if (scores.isFull())
        cout << "All spaces used" << endl;

    cout << "Front score: " << scores.front() << endl;

    for (int count = 0; count < 5; count++)
        scores.dequeue();

    if (scores.isEmpty())
        cout << "No scores left" << endl;

    return 0;
}