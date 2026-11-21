
#include <iostream>
using namespace std;

struct PatientNode {
    int patientID;
    PatientNode* next; // Points to the next patient in line.
};

class HospitalQueue {
private:
    PatientNode* firstPatient;
    PatientNode* lastPatient;
    int totalPatients;

public:
    HospitalQueue() {
        // 1. Start with no first or last patient and set the count to zero.
        firstPatient = nullptr;
        lastPatient = nullptr;
        totalPatients = 0;
    }

    bool isEmpty() const {
        // 1. The queue is empty if firstPatient points to nothing.
        return firstPatient == nullptr;
    }

    // Task 1 (4 marks) adds a patient to the back of the queue.
    void enqueue(int patientID) {
        // 1. new PatientNode creates the node and newNode stores its address.
        PatientNode* newNode = new PatientNode;
        // 2. Store the patient's ID in the node.
        newNode->patientID = patientID;

        newNode->next = nullptr; // This patient will be last in line.

        // 3. In an empty queue, both pointers refer to the new patient.
        if (isEmpty()) {
            firstPatient = newNode;
            lastPatient = newNode;
        } else {
            // 4. Link the new patient after the old last patient, then update lastPatient.
            lastPatient->next = newNode;

            lastPatient = newNode;
        }
        // 5. Increase the number of patients waiting.
        totalPatients++;

    }

    // Task 2 (4 marks) removes the first patient and returns their ID.
    int dequeue() {
        // 1. Return -1 if there is no patient to treat.
        if (isEmpty()) {
            return -1;
        }
        // 2. Save the first node and copy its patient ID before deletion.
        PatientNode* nodeToDelete = firstPatient;
        int number = nodeToDelete->patientID;

        // 3. Make the next patient first in line.
        firstPatient = firstPatient->next;

        // 4. Clear lastPatient too if there are no patients left.
        if (firstPatient == nullptr) {
            lastPatient = nullptr;
        }
        // 5. Free the old first node and reduce the patient count.
        delete nodeToDelete;
        totalPatients--;

        // 6. Return the saved patient ID.
        return number;

    }

    // Task 3 (3 marks) displays the patient IDs in queue order.
    void displayQueue() const {
        // 1. Print the empty-queue message and return if nobody is waiting.
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        // 2. Start a temporary pointer at the first patient.
        PatientNode* current = firstPatient;

        // 3. Print each ID on the same line and follow next until the queue ends.
        while (current != nullptr) {
            cout << current->patientID;
            current = current->next;
        }
        // 4. Print the rear label and end the line.
        cout << "<- Rear" << endl;
    }

    int waiting() const {
        // 1. Return the number of patients currently waiting.
        return totalPatients;
    }

    ~HospitalQueue() {
        // 1. Use dequeue to free the remaining nodes when the queue is destroyed.
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    // 1. Add three patients to a new queue and display their order.
    HospitalQueue emergencyLine;

    emergencyLine.enqueue(810);
    emergencyLine.enqueue(820);
    emergencyLine.enqueue(830);

    emergencyLine.displayQueue();

    // 2. Treat the first patient, add another, and show the new queue and count.
    cout << "Patient treated: "
         << emergencyLine.dequeue() << endl;

    emergencyLine.enqueue(840);

    emergencyLine.displayQueue();

    cout << "Patients waiting: "
         << emergencyLine.waiting() << endl;

    // 3. Treat the three remaining patients and display the empty queue.
    cout << "Patient treated: "
         << emergencyLine.dequeue() << endl;

    cout << "Patient treated: "
         << emergencyLine.dequeue() << endl;

    cout << "Patient treated: "
         << emergencyLine.dequeue() << endl;

    emergencyLine.displayQueue();

    // 4. Try treating a patient from the empty queue.
    if (emergencyLine.dequeue() == -1) {
        cout << "No patients waiting" << endl;
    }

    // 5. Add a patient to the empty queue and show its new contents and count.
    emergencyLine.enqueue(850);

    emergencyLine.displayQueue();

    cout << "Patients waiting: "
         << emergencyLine.waiting() << endl;

    return 0;
}
