
#include <iostream>
using namespace std;

struct StudentNode {
    int studentID;
    StudentNode* next; // Points to the next student in the list.
};

// Task 1 (3 marks) displays the students in the list.
void displayStudents(StudentNode* head) {
    // 1. Start a temporary pointer at the first student.
    StudentNode* current = head;

    // 2. Keep visiting students until current reaches nullptr.
    while (current != nullptr) {
        // 3. Print this student's ID and move to the next node.
        cout << current->studentID << " -> ";
        current = current->next;
    }
    // 4. Print NULL to mark the end of the list.
    cout << "NULL" << endl;
}


// Task 2 (4 marks) adds a student at the end of the list.
void insertAtEnd(StudentNode*& head, int studentID) {
    // 1. new StudentNode creates the node and newNode stores its address.
    StudentNode* newNode = new StudentNode;
    // 2. Store the ID and set next to nullptr because this will be the last node.
    newNode->studentID = studentID;

    newNode->next = nullptr;

    // The steps below are unfinished. A null head means the list is empty.
    // 3. For an empty list, set head to the new node and return.
    if (isEmpty()) {
    }

    // 4. Otherwise, follow next from head to the last node.
    // 5. Connect that last node to newNode.
}


// Task 3 (5 marks) removes a student by position, counting from 1.
bool removeAtPosition(StudentNode*& head, int position) {
    // Implement these steps here.
    // 1. Return false if the list is empty or position is less than 1.
    // 2. At position 1, save head, advance it, delete the old head, and return true.
    // 3. Otherwise, walk from head to the node just before the requested position.
    // 4. Return false if that node or its next pointer is nullptr.
    // 5. Link the previous node to the node after the one being removed.
    // 6. Delete the removed node to free its memory.
    // 7. Return true to report successful removal.
}


int main() {

    // 1. Start with an empty list and add four student IDs.
    StudentNode* registrationList = nullptr;

    insertAtEnd(registrationList, 1001);
    insertAtEnd(registrationList, 1002);
    insertAtEnd(registrationList, 1003);
    insertAtEnd(registrationList, 1004);

    displayStudents(registrationList);

    // 2. Try removing the second student and display the result.
    if (removeAtPosition(registrationList, 2)) {
        cout << "Removed position 2" << endl;
    }

    displayStudents(registrationList);

    // 3. Test removing the first student.
    if (removeAtPosition(registrationList, 1)) {
        cout << "Removed position 1" << endl;
    }

    displayStudents(registrationList);

    // 4. Add a student at the end and display the list again.
    insertAtEnd(registrationList, 1005);

    displayStudents(registrationList);

    // 5. Try a position beyond the end of the list.
    if (!removeAtPosition(registrationList, 8)) {
        cout << "Position 8 does not exist" << endl;
    }

    displayStudents(registrationList);

    // 6. Free each remaining node after saving its successor in registrationList.
    while (registrationList != nullptr) {
        StudentNode* temp = registrationList;
        registrationList = registrationList->next;
        delete temp;
    }

    return 0;
}
