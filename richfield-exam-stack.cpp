#include <iostream>
using namespace std;

const int MAX_SCRIPTS = 5;

class ScriptStack {
private:
    int scriptNumbers[MAX_SCRIPTS];
    int stackTop;
public:
    ScriptStack() {
        stackTop = 0;
    }
    bool isEmpty() const {
        return stackTop == 0;
    }
    bool isFull() const {
        return stackTop == MAX_SCRIPTS;
    }
    void push(int scriptNumber) {
        if (isFull()) {
            cout << "Overflow: " << scriptNumber << "Cannot be added" << endl;
            return;
        }
        scriptNumbers[stackTop] = scriptNumber;
        stackTop++;
    }
    int pop() {
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }
        stackTop--;
        return scriptNumbers[stackTop];
    }
    int peekTop() const {
        if (isEmpty()) {
            cout << "It is empty" << endl;
            return -1;
        }
        return scriptNumbers[stackTop - 1];
    }
    int numberOfScripts() const {
        return stackTop;
    }

};

int main() {
    ScriptStack markingPile;

    for (int scriptNumber = 301; scriptNumber <= 306; scriptNumber++)
        markingPile.push(scriptNumber);
    cout << "Top script: " << markingPile.peekTop() << endl;
    cout << "Scripts stacked: " << markingPile.numberOfScripts() << endl;
    cout << "Marking script: " << markingPile.pop() << endl;
    cout << "Marking script: " << markingPile.pop() << endl;
    cout << "Top script: " << markingPile.peekTop() << endl;

    while (!markingPile.isEmpty())
        markingPile.pop();
    markingPile.peekTop();
    markingPile.pop();
    return 0;
}