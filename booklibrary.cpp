#include <iostream>
#include <string>
using namespace std;

struct nodeType {
    string title;
    nodeType* link;
};

void insertFirst(nodeType*& head, string t) {
    nodeType* n = new nodeType;   // 1. create a node on the heap
    n->title = t;                 // 2. fill it
    n->link = head;               // 3. link it to the OLD first node
    head = n;                     // 4. THEN move head to it
}

void insertLast(nodeType*& head, string t) {
    nodeType* n = new nodeType;
    n->title = t;
    n->link = nullptr;            // it will be the LAST node, so nothing follows it
    if (head == nullptr) {        // empty list: the new node is the whole list
        head = n;
    } else {
        nodeType* cur = head;
        while (cur->link != nullptr)   // stop ON the last node
            cur = cur->link;
        cur->link = n;                 // attach the new node after it
    }
}

void printList(nodeType* head) {
    nodeType* cur = head;
    while (cur != nullptr) {
        cout << cur->title << endl;
        cur = cur->link;
    }
}

void deleteFirst(nodeType*& head) {
    if (head == nullptr)          // empty list: nothing to delete
        return;
    nodeType* temp = head;        // remember the first node
    head = head->link;            // head skips it
    delete temp;                  // free its memory
}

bool deleteTitle(nodeType*& head, const string& t) {
    if (head == nullptr)          // empty list
        return false;
    if (head->title == t) {       // the first node holds it: no previous node exists
        nodeType* temp = head;
        head = head->link;
        delete temp;
        return true;
    }
    nodeType* p = head;           // p = the node BEFORE the one we are testing
    while (p->link != nullptr && p->link->title != t)
        p = p->link;
    if (p->link == nullptr)       // reached the end: not found
        return false;
    nodeType* temp = p->link;     // the node to delete
    p->link = temp->link;         // unlink: p now skips it
    delete temp;                  // free it
    return true;
}

int main() {
    nodeType* head = nullptr;
    insertLast(head, "Hamlet");
    insertLast(head, "Romeo and Juliet");
    insertLast(head, "Macbeth");
    insertFirst(head, "Othello");
    printList(head);
    cout << "---" << endl;
    deleteTitle(head, "Romeo and Juliet");
    deleteFirst(head);
    printList(head);

    while (head != nullptr)       // free whatever is left before the program ends
        deleteFirst(head);
    return 0;
}