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
    // 1. Constructor: a new stack contains no items.
    IntStack() {
        stackTop = 0;
    }

    // 2. Return true if the stack contains no items.
    // const means this function does not change the object.
    bool isEmpty() const {
        return stackTop == 0;
    }

    // Return true if all available array positions are occupied.
    bool isFull() const {
        return stackTop == MAX_SIZE;
    }

    // 3. Add an integer to the top of the stack.
    void push(int newItem) {
        if (isFull()) {
            // Do not add an item when the array is full.
            cout << "Stack is full" << endl;
        } else {
            // Store the integer in the next free position.
            items[stackTop] = newItem;

            // Increase the number of stored items.
            stackTop++;
        }
    }

    // 4. Remove the top integer from the stack.
    void pop() {
        if (isEmpty()) {
            // There is no item to remove.
            cout << "Stack is empty" << endl;
        } else {
            // Decrease the count so the previous top is no longer included.
            // The array value does not need to be erased.
            stackTop--;
        }
    }

    // 5. Return the top integer without removing it.
    // Arrays start at index 0, so the top is at stackTop - 1.
    // Only call this function when the stack is not empty.
    int top() const {
        return items[stackTop - 1];
    }
};

// 6. Test adding items, reading the top, removing items,
// checking for an empty stack, and trying to exceed the capacity.
int main() {
    IntStack numberStack;
    numberStack.push(10);
    numberStack.push(20);
    numberStack.push(30);
    cout << "Top: " << numberStack.top() << endl;
    numberStack.pop();
    cout << "Top: " << numberStack.top() << endl;
    numberStack.pop();
    numberStack.pop();
    numberStack.pop();
    if (numberStack.isEmpty())
        cout << "Stack is now empty" << endl;
    for (int number = 1; number <= 6; number++)
        numberStack.push(number);
    cout << "Top: " << numberStack.top() << endl;
    return 0;
}