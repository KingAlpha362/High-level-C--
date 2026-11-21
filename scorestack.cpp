#include <iostream>

using namespace std;

const int MAX_SIZE = 4;

class ScoreStack {
private:
    int stackTop; // Counts the scores and gives the next free index when there is room.
    int items[MAX_SIZE];

public:

    ScoreStack() {
        // 1. Set the score count to zero when the stack is created.
        stackTop = 0;
    }

    bool isEmpty() const {
        // 1. A count of zero means there are no scores to pop.
        return stackTop == 0;
    }

    bool isFull() const {
        // 1. Check whether the count has reached the number of available slots.
        return stackTop == MAX_SIZE;
    }

    void push(int score) {
        // 1. Print a message if the stack is already full.
        if (isFull()) {
            cout << "Stack is full" << endl;
        } else {
            // 2. Store the score at the next free index.
            items[stackTop] = score;

            // 3. Count the new score and advance the index.
            stackTop++;
        }
    }

    void pop() {
    // 1. Print a message if there is no score to remove.
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        // 2. Decrease the count so the old top slot becomes available again.
        stackTop--;
    }
}

    int top() const {
        // 1. Read the most recent score at stackTop - 1. This requires a nonempty stack.
        return items[stackTop - 1];
    }
};

int main() {
    // 1. Push three scores and show the most recently added one.
    ScoreStack scores;

    scores.push(45);
    scores.push(60);
    scores.push(75);
    cout << "Top score: " << scores.top() << endl;

    // 2. Remove the top score and read the score underneath it.
    scores.pop();
    cout << "Top score: " << scores.top() << endl;

    // 3. Fill the two free slots and try pushing another score.
    scores.push(80);
    scores.push(95);
    scores.push(100);

    if (scores.isFull())
        cout << "All spaces used" << endl;

    cout << "Top score: " << scores.top() << endl;

    // 4. Remove four scores and attempt one more pop from the empty stack.
    for (int count = 0; count < 5; count++)
        scores.pop();

    if (scores.isEmpty())
        cout << "No scores left" << endl;

    return 0;
}