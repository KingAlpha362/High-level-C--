#include <iostream>
#include <string>
using namespace std;

struct nodeType {
    string title;
    nodeType* link; // Points to the next book in the list.
};

void insertFirst(nodeType*& head, string t) {
    // 1. Create a new book node in memory and save its address in n.
    nodeType* n = new nodeType;
    // 2. Store the book title in that node.
    n->title = t;
    // 3. Point the new node to the old first book.
    n->link = head;
    // 4. Update the caller's head pointer to make this book first.
    head = n;
}

void insertLast(nodeType*& head, string t) {
    // 1. Create a book node and store its title.
    nodeType* n = new nodeType;
    n->title = t;
    n->link = nullptr; // No book comes after the new last node.

    // 2. If the list is empty, the new node becomes the first book too.
    if (head == nullptr) {
        head = n;
    } else {
        // 3. Follow each link until cur points to the last book.
        nodeType* cur = head;
        while (cur->link != nullptr)
            cur = cur->link;
        // 4. Attach the new book after the old last book.
        cur->link = n;
    }
}

void printList(nodeType* head) {
    // 1. Start at the first book with a temporary pointer.
    nodeType* cur = head;
    // 2. Print each title and follow its link until the list ends.
    while (cur != nullptr) {
        cout << cur->title << endl;
        cur = cur->link;
    }
}

void deleteFirst(nodeType*& head) {
    // 1. Return early if the list is empty.
    if (head == nullptr)
        return;
    // 2. Keep the old first node while moving head to the next book.
    nodeType* temp = head;
    head = head->link;
    // 3. Free the old first node.
    delete temp;
}

bool deleteTitle(nodeType*& head, const string& t) {
    // 1. Return false if there are no books to search.
    if (head == nullptr)
        return false;
    // 2. If the first book matches, remove it by updating head.
    if (head->title == t) {
        nodeType* temp = head; // Keep the old first node for deletion.
        head = head->link;    // Move head to the next book.
        delete temp;         // Free the old first node.
        return true;         // Report a successful removal.
    }

    // 3. Look one book ahead so p stops before the matching node.
    nodeType* p = head;
    while (p->link != nullptr && p->link->title != t)
        p = p->link;
    // 4. A null link means the search reached the end without a match.
    if (p->link == nullptr)
        return false;

    // 5. Save the matching node and link its predecessor to the next book.
    nodeType* temp = p->link;
    p->link = temp->link;
    // 6. Free the removed node and report success.
    delete temp;
    return true;
}

int main() {
    // 1. Start with an empty list, append three books, and insert one at the front.
    nodeType* head = nullptr;
    insertLast(head, "Hamlet");
    insertLast(head, "Romeo and Juliet");
    insertLast(head, "Macbeth");
    insertFirst(head, "Othello");
    printList(head);
    cout << "---" << endl;
    // 2. Remove a book by title, remove the first book, and show what remains.
    deleteTitle(head, "Romeo and Juliet");
    deleteFirst(head);
    printList(head);

    // 3. Delete the remaining books one at a time to free their memory.
    while (head != nullptr)
        deleteFirst(head);
    return 0;
}