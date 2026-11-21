#include <iostream>
using namespace std;

const int MAX_SCRIPTS = 5;

class ScriptStack {
private:
    int scriptNumbers[MAX_SCRIPTS];
    int stackTop; // Counts scripts and gives the next free index when there is room.
public:
    ScriptStack() {
        // 1. Start with zero scripts in the marking pile.
        stackTop = 0;
    }
    bool isEmpty() const {
        // 1. Check whether there are zero scripts left.
        return stackTop == 0;
    }
    bool isFull() const {
        // 1. Check whether all the available script slots are occupied.
        return stackTop == MAX_SCRIPTS;
    }
    void push(int scriptNumber) {
        // 1. Report overflow and return if there is no room for another script.
        if (isFull()) {
            cout << "Overflow: " << scriptNumber << "Cannot be added" << endl;
            return;
        }
        // 2. Store the script number at the next free index.
        scriptNumbers[stackTop] = scriptNumber;
        // 3. Count the script that was just added.
        stackTop++;
    }
    int pop() {
        // 1. Report underflow and return -1 if there is no script to remove.
        if (isEmpty()) {
            cout << "Underflow" << endl;
            return -1;
        }
        // 2. Move stackTop back to the index of the script being removed.
        stackTop--;
        // 3. Return that script number.
        return scriptNumbers[stackTop];
    }
    int peekTop() const {
        // 1. Return -1 with a message if there is no top script.
        if (isEmpty()) {
            cout << "It is empty" << endl;
            return -1;
        }
        // 2. Read the top script at the occupied index just below stackTop.
        return scriptNumbers[stackTop - 1];
    }
    int numberOfScripts() const {
        // 1. Return the number of scripts recorded in stackTop.
        return stackTop;
    }

};

int main() {
    // 1. Fill the marking pile and try adding one script beyond its capacity.
    ScriptStack markingPile;

    for (int scriptNumber = 301; scriptNumber <= 306; scriptNumber++)
        markingPile.push(scriptNumber);
    // 2. Show the top script and the number of scripts in the pile.
    cout << "Top script: " << markingPile.peekTop() << endl;
    cout << "Scripts stacked: " << markingPile.numberOfScripts() << endl;
    // 3. Take the top two scripts for marking and show the new top.
    cout << "Marking script: " << markingPile.pop() << endl;
    cout << "Marking script: " << markingPile.pop() << endl;
    cout << "Top script: " << markingPile.peekTop() << endl;

    // 4. Empty the pile and test reading and removing from an empty stack.
    while (!markingPile.isEmpty())
        markingPile.pop();
    markingPile.peekTop();
    markingPile.pop();
    return 0;
}