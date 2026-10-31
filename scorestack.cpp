#include <iostream>

using namespace std;

const int MAX_SIZE = 4;

class ScoreStack {
private:
    int stackTop;
    int items[MAX_SIZE];

public:

    ScoreStack() {
        stackTop = 0;
    }

    bool isEmpty() const {
        return stackTop == 0;
    }

    bool isFull() const {
        return stackTop == MAX_SIZE;
    }

    void push(int score) {
        if (isFull()) {
            cout << "Stack is full" << endl;
        } else {
            items[stackTop] = score;

            stackTop++;
        }
    }

    void pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        stackTop--;
    }
}

    int top() const {
        return items[stackTop - 1];
    }
};

int main() {
    ScoreStack scores;

    scores.push(45);
    scores.push(60);
    scores.push(75);
    cout << "Top score: " << scores.top() << endl;

    scores.pop();
    cout << "Top score: " << scores.top() << endl;

    scores.push(80);
    scores.push(95);
    scores.push(100);

    if (scores.isFull())
        cout << "All spaces used" << endl;

    cout << "Top score: " << scores.top() << endl;

    for (int count = 0; count < 5; count++)
        scores.pop();

    if (scores.isEmpty())
        cout << "No scores left" << endl;

    return 0;
}