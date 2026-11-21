#include <iostream>
using namespace std;

const int MAXIMUM_TRAYS = 5;

class TrayStack {
private:
    int trayNumbers[MAXIMUM_TRAYS];
    int stackTop; // Counts trays and gives the next free index when there is room.
public:
    TrayStack() {
        // 1. Start with zero trays on the stack.
        stackTop = 0;
    }
    bool isEmpty() const {
        // 1. A count of zero means there are no trays left.
        return stackTop == 0;
    }
    bool isFull() const {
        // 1. A count of MAXIMUM_TRAYS means every slot is in use.
        return stackTop == MAXIMUM_TRAYS;
    }
    void push(int trayNumber) {
        // 1. Report overflow and return if the stack is full.
        if (isFull()) {
            cout << "Overflow" << trayNumber << "The stack is full" << endl;
            return;
        }
        // 2. Put the tray number in the next free slot.
        trayNumbers[stackTop] = trayNumber;
        // 3. Increase the number of trays on the stack.
        stackTop++;
    }
    int pop() {
        // 1. Print a message and return -1 if there is no tray to remove.
        if (isEmpty()) {
            cout << "The stack is empty" << endl;
            return -1;
        }
        // 2. Reduce the count so stackTop gives the index of the removed tray.
        stackTop--;
        // 3. Return the tray number from that index.
        return trayNumbers[stackTop];
    }
    int topTray() const {
        // 1. Read the previous slot at stackTop - 1. This requires at least one tray.
        return trayNumbers[stackTop - 1];
    }
    int numberOfTrays() const {
        // 1. Return the current tray count.
        return stackTop;
    }
};

int main() {
    // 1. Fill the stack with five trays and try adding a sixth.
    TrayStack canteenTrays;
    for (int trayNumber = 101; trayNumber <= 106; trayNumber++)
        canteenTrays.push(trayNumber);
    // 2. Show the tray count and read the top tray number.
    cout << "Trays on the stack: " << canteenTrays.numberOfTrays() << endl;
    cout << "Top tray: " << canteenTrays.topTray() << endl;

    // 3. Remove two trays, print their numbers, and show the new top tray.
    int firstRemoved = canteenTrays.pop();
    int secondRemoved = canteenTrays.pop();
    cout << "Removed: " << firstRemoved << " and " << secondRemoved << endl;
    cout << "Top tray: " << canteenTrays.topTray() << endl;

    // 4. Remove the rest of the trays and try popping from the empty stack.
    while (!canteenTrays.isEmpty())
        canteenTrays.pop();
    canteenTrays.pop();
    return 0;
}