#include <iostream>
using namespace std;

// Maximum number of integers the stack can store.
const int MAX_SIZE = 5;

class IntStack {
private:
    // stackTop counts the stored items and identifies the next free position.
    int stackTop;

    // Fixed-size array used to store the integers.
    int items[MAX_SIZE];

public:
    IntStack() {
        // 1. Start with zero items, so index 0 is the first free slot.
        stackTop = 0;
    }

    bool isEmpty() const { // const marks this as a read-only operation.
        // 1. Check whether the stack contains zero items.
        return stackTop == 0;
    }

    bool isFull() const {
        // 1. Check whether the count has reached the array capacity.
        return stackTop == MAX_SIZE;
    }

    void push(int newItem) {
        // 1. Report that the stack is full if every slot is occupied.
        if (isFull()) {
            cout << "Stack is full" << endl;
        } else {
            // 2. Store the integer in the next free slot at stackTop.
            items[stackTop] = newItem;

            // 3. Count the new item and move to the next free index.
            stackTop++;
        }
    }

    void pop() {
        // 1. Report that the stack is empty if there is nothing to remove.
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            // 2. Reduce the count so the old top slot becomes available again.
            stackTop--;
        }
    }

    int top() const {
        // 1. Read the occupied slot just below stackTop. This requires a nonempty stack.
        return items[stackTop - 1];
    }
};

int main() {
    // 1. Push three integers and show the top value, 30.
    IntStack numberStack;
    numberStack.push(10);
    numberStack.push(20);
    numberStack.push(30);
    cout << "Top: " << numberStack.top() << endl;
    // 2. Remove the top value and show that 20 is now on top.
    numberStack.pop();
    cout << "Top: " << numberStack.top() << endl;
    // 3. Remove the last two items, then try popping from an empty stack.
    numberStack.pop();
    numberStack.pop();
    numberStack.pop();
    if (numberStack.isEmpty())
        cout << "Stack is now empty" << endl;
    // 4. Fill the five slots, try pushing a sixth value, and read the top.
    for (int number = 1; number <= 6; number++)
        numberStack.push(number);
    cout << "Top: " << numberStack.top() << endl;
    return 0;
}