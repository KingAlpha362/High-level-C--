#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    int mark;
    Node* next;

    Node(string studentName, int studentMark) {
        name = studentName;
        mark = studentMark;
        next = nullptr;
    }
};

int main() {
    Node* firstStudent = new Node("Thabo", 65);
    Node* secondStudent = new Node("Lerato", 78);
    Node* thirdStudent = new Node("Sipho", 52);

    firstStudent->next = secondStudent;
    secondStudent->next = thirdStudent;
    thirdStudent->next = nullptr;

    Node* head = firstStudent;

    Node* fourthStudent = new Node("Naledi", 70);
    fourthStudent->next = head;

    Node* current = head;
    while (current != nullptr) {
        cout << current->name << ": " << current->mark << endl;
        current = current->next;
    }

    current = head;
    Node* best = head;
    while (current != nullptr) {
        if (current->mark > best->mark) {
            best = current;
        }
        current = current->next;
    }
    cout << "Highest: " << best->name << " with " << best->mark << endl;

    while (head != nullptr) {
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }
    
    cout << "All nodes freed" << endl;

    return 0;
} 