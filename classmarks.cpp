#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    int mark;
    Node* next; // Points to the next student in the list.

    Node(string studentName, int studentMark) {
        // 1. Save the student's name and mark in this node.
        name = studentName;
        mark = studentMark;
        // 2. Start with no next student until this node is linked.
        next = nullptr;
    }
};

int main() {
    // 1. Create three student nodes with new and store their addresses.
    Node* firstStudent = new Node("Thabo", 65);
    Node* secondStudent = new Node("Lerato", 78);
    Node* thirdStudent = new Node("Sipho", 52);

    // 2. Link the students in order and end the list with nullptr.
    firstStudent->next = secondStudent;
    secondStudent->next = thirdStudent;
    thirdStudent->next = nullptr;

    // 3. Make head identify the first student in the list.
    Node* head = firstStudent;

    // 4. Create Naledi's node and point it to the current first student.
    Node* fourthStudent = new Node("Naledi", 70);
    fourthStudent->next = head; // head still points to Thabo, so traversal skips Naledi.

    // 5. Start at head and print each student's name and mark.
    Node* current = head;
    while (current != nullptr) {
        cout << current->name << ": " << current->mark << endl;
        current = current->next;
    }

    // 6. Restart at head and remember the node with the highest mark seen so far.
    current = head;
    Node* best = head; // Use the first student's mark as the starting comparison.
    while (current != nullptr) {
        if (current->mark > best->mark) {
            best = current;
        }
        current = current->next;
    }
    cout << "Highest: " << best->name << " with " << best->mark << endl;

    // 7. Free the nodes reachable from head.
    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next; // Move head before freeing the old node.
        delete nodeToDelete;
    }
    
    cout << "All nodes freed" << endl;

    return 0;
} 