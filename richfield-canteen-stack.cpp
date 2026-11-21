#include <iostream>
using namespace std;

const int MAXIMUM_TRAYS = 5;

class TrayStack {
private:
    int trayNumbers[MAXIMUM_TRAYS];
    int stackTop;
public:
    TrayStack() {
        stackTop = 0;
    }
    bool isEmpty() const {
        return stackTop == 0;
    }
    bool isFull() const {
        return stackTop == MAXIMUM_TRAYS;
    }
    void push(int trayNumber) {
        if (isFull()) {
            cout << "Overflow" << trayNumber << "The stack is full" << endl;
            return;
        }
        trayNumbers[stackTop] = trayNumber;
        stackTop++;
    }
    int pop() {
        if (isEmpty()) {
            cout << "The stack is empty" << endl;
            return -1;
        }
        stackTop--;
        return trayNumbers[stackTop];
    }
    int topTray() const {
        return trayNumbers[stackTop - 1];
    }
    int numberOfTrays() const {
        return stackTop;
    }
};

int main() {
    TrayStack canteenTrays;
    for (int trayNumber = 101; trayNumber <= 106; trayNumber++)
        canteenTrays.push(trayNumber);
    cout << "Trays on the stack: " << canteenTrays.numberOfTrays() << endl;
    cout << "Top tray: " << canteenTrays.topTray() << endl;

    int firstRemoved = canteenTrays.pop();
    int secondRemoved = canteenTrays.pop();
    cout << "Removed: " << firstRemoved << " and " << secondRemoved << endl;
    cout << "Top tray: " << canteenTrays.topTray() << endl;

    while (!canteenTrays.isEmpty())
        canteenTrays.pop();
    canteenTrays.pop();
    return 0;
}