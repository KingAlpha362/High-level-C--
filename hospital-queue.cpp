
#include <iostream>
using namespace std;

struct PatientNode {
    int patientID;
    PatientNode* next;
};

class HospitalQueue {
private:
    PatientNode* firstPatient;
    PatientNode* lastPatient;
    int totalPatients;

public:
    HospitalQueue() {
        firstPatient = nullptr;
        lastPatient = nullptr;
        totalPatients = 0;
    }

    bool isEmpty() const {
        return firstPatient == nullptr;
    }

    // TASK 1: ENQUEUE (4 MARKS)
    // Create a new PatientNode using new.
    // Store the patientID and set next to nullptr.
    // If empty, update firstPatient and lastPatient.
    // Otherwise, link the new node at the rear.
    // Increase totalPatients.

    void enqueue(int patientID) {
        // WRITE YOUR CODE HERE
        PatientNode* newNode = new PatientNode;
        newNode->patientID = patientID;

        newNode->next = nullptr;

        if (isEmpty()) {
            firstPatient = newNode;
            lastPatient = newNode;
        } else {
            lastPatient->next = newNode;

            lastPatient = newNode;
        }
        totalPatients++;

    }

    // TASK 2: DEQUEUE (4 MARKS)
    // If empty, return -1.
    // Save the first node and its patientID.
    // Move firstPatient to the next node.
    // If the queue becomes empty, reset lastPatient.
    // Delete the old node.
    // Decrease totalPatients.
    // Return the removed patientID.

    int dequeue() {
        // WRITE YOUR CODE HERE
        if (isEmpty()) {
            return -1;
        }
        PatientNode* nodeToDelete = firstPatient;
        int number = nodeToDelete->patientID;

        firstPatient = firstPatient->next;

        if (firstPatient == nullptr) {
            lastPatient = nullptr;
        }
        delete nodeToDelete;
        totalPatients--;

        return number;

    }

    // TASK 3: DISPLAY QUEUE (3 MARKS)
    // If empty, print "Queue is empty" and return.
    // Start a temporary pointer at firstPatient.
    // Display all patient IDs from front to rear.
    // Print everything on ONE line.

    void displayQueue() const {
        // WRITE YOUR CODE HERE
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        PatientNode* current = firstPatient;

        while (current != nullptr) {
            cout << current->patientID;
            current = current->next;
        }
        cout << "<- Rear" << endl;
    }

    int waiting() const {
        return totalPatients;
    }

    ~HospitalQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    HospitalQueue emergencyLine;

    emergencyLine.enqueue(810);
    emergencyLine.enqueue(820);
    emergencyLine.enqueue(830);

    emergencyLine.displayQueue();

    cout << "Patient treated: "
         << emergencyLine.dequeue() << endl;

    emergencyLine.enqueue(840);

    emergencyLine.displayQueue();

    cout << "Patients waiting: "
         << emergencyLine.waiting() << endl;

    cout << "Patient treated: "
         << emergencyLine.dequeue() << endl;

    cout << "Patient treated: "
         << emergencyLine.dequeue() << endl;

    cout << "Patient treated: "
         << emergencyLine.dequeue() << endl;

    emergencyLine.displayQueue();

    if (emergencyLine.dequeue() == -1) {
        cout << "No patients waiting" << endl;
    }

    emergencyLine.enqueue(850);

    emergencyLine.displayQueue();

    cout << "Patients waiting: "
         << emergencyLine.waiting() << endl;

    return 0;
}
