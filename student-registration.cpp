
#include <iostream>
using namespace std;

struct StudentNode {
    int studentID;
    StudentNode* next;
};

// TASK 1: DISPLAY STUDENTS (3 MARKS)
// 1. Create a temporary pointer starting at head.
// 2. Loop until nullptr, moving to the next node.
// 3. Display each studentID followed by " -> ".
// 4. Finish the output with "NULL".

void displayStudents(StudentNode* head) {
    // WRITE YOUR CODE HERE
    StudentNode* current = head;

    while (current != nullptr) {
        cout << current->studentID << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}


// TASK 2: INSERT AT END (4 MARKS)
// 1. Create a new node using new.
// 2. Store studentID and set next to nullptr.
// 3. If the list is empty, make head the new node.
// 4. Otherwise, traverse to the LAST node.
// 5. Connect the last node to the new node.

void insertAtEnd(StudentNode*& head, int studentID) {
    // WRITE YOUR CODE HERE
    StudentNode* newNode = new StudentNode;
    newNode->studentID = studentID;

    newNode->next = nullptr;
    
    if (head == nullptr) {
        newNode = head;
        return;
    }

    StudentNode* current = head;
    while (current != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}


// TASK 3: REMOVE AT POSITION (5 MARKS)
// 1. Return false if the list is empty
//    or position is less than 1.
// 2. If position is 1:
//    - Save the head node.
//    - Move head to the next node.
//    - Delete the old head.
//    - Return true.
// 3. Otherwise, traverse to the node BEFORE
//    the node to be removed.
// 4. If the position does not exist,
//    return false.
// 5. Bypass the node being removed.
// 6. Delete the removed node.
// 7. Return true.

bool removeAtPosition(StudentNode*& head, int position) {
    // 1. Return false if the list is empty or position is less than 1.
    if (head == nullptr || position < 1) {
        return false;
    }

    // 2. If position is 1:
    if (position == 1) {
        StudentNode* temp = head; // Save the head node
        head = head->next;        // Move head to the next node
        delete temp;              // Delete the old head
        return true;              // Return true
    }

    // 3. Otherwise, traverse to the node BEFORE the node to be removed.
    StudentNode* prev = head;
    for (int i = 1; i < position - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    // 4. If the position does not exist, return false.
    if (prev == nullptr || prev->next == nullptr) {
        return false;
    }

    // 5. Bypass the node being removed.
    StudentNode* nodeToDelete = prev->next;
    prev->next = nodeToDelete->next;

    // 6. Delete the removed node.
    delete nodeToDelete;

    // 7. Return true.
    return true;
}


int main() {

    StudentNode* registrationList = nullptr;

    insertAtEnd(registrationList, 1001);
    insertAtEnd(registrationList, 1002);
    insertAtEnd(registrationList, 1003);
    insertAtEnd(registrationList, 1004);

    displayStudents(registrationList);

    if (removeAtPosition(registrationList, 2)) {
        cout << "Removed position 2" << endl;
    }

    displayStudents(registrationList);

    if (removeAtPosition(registrationList, 1)) {
        cout << "Removed position 1" << endl;
    }

    displayStudents(registrationList);

    insertAtEnd(registrationList, 1005);

    displayStudents(registrationList);

    if (!removeAtPosition(registrationList, 8)) {
        cout << "Position 8 does not exist" << endl;
    }

    displayStudents(registrationList);

    // Free all remaining nodes.
    while (registrationList != nullptr) {
        StudentNode* temp = registrationList;
        registrationList = registrationList->next;
        delete temp;
    }

    return 0;
}
