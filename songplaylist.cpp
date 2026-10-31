#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string title;
    int minutes;
    Node* next;

    Node(string songTitle, int musicMinutes) { // Added a constructor that receives title
        title = songTitle;                 // and minutes, stores them and sets next to nullptr.
        minutes = musicMinutes;
        next = nullptr;
    }
};

int main() {
    Node first("Jerusalema", 5); // create local object first
    Node second("Calm Down", 4); // create local object second
    Node third("Water", 3); // create local object third

    first.next = &second; // linking the songs in order
    second.next = &third;
    third.next = nullptr;

    Node* head = &first;  // head stores the address of the first node in the list

    Node fourth("Essence", 4); // create new song as local object

    fourth.next = head; // this links fourth to the current first node

    head = &fourth; // this moves head to fourth, making fourth the new first node

    // The list is now: fourth -> first -> second -> third -> nullptr.

    // to display
    Node* current = head; // use a pointer called current to visit each node, starting at head

   // Continue until current reaches nullptr, the end of the list.

   while (current != nullptr) {
         // -> accesses a member of the node that current points to
        // Print each song in the format: Title - 4 min.
    cout << current->title << " - "
         << current->minutes << " min" << endl;

        // Move to the next node
        current = current->next;

        // Part 5: Count and total (6 marks)
       // Use ONE loop to count the songs and add up their minutes.
       int songs = 0;
       int total = 0;

       // Reset current to head because the display loop left it at nullptr
       current = head;

       while (current != nullptr) {
        songs++;                     // Count the current song.
        total += current->minutes;  // Add its duration to the total.
        current = current->next;   // Move to the next node.
       }

       // Expected results: Songs: 4 and Total minutes: 16.
       cout << "Songs: " << songs << endl;
       cout << "Total minutes: " << total << endl;

    return 0;
   }

    


}