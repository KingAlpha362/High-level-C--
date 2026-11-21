#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string title;
    int minutes;
    Node* next; // Points to the next song in the playlist.

    Node(string songTitle, int musicMinutes) {
        // 1. Store the title and duration in this song node.
        title = songTitle;
        minutes = musicMinutes;
        // 2. Start with no next song until this node is linked.
        next = nullptr;
    }
};

int main() {
    // 1. Create three songs as local nodes.
    Node first("Jerusalema", 5);
    Node second("Calm Down", 4);
    Node third("Water", 3);

    // 2. Link the songs in order using their addresses.
    first.next = &second; // &second gives the address of the second song.
    second.next = &third;
    third.next = nullptr;

    // 3. Save the address of the first song in head.
    Node* head = &first;

    // 4. Insert Essence before the current first song.
    Node fourth("Essence", 4);

    fourth.next = head; // Link Essence to the old first song.

    head = &fourth; // Move head so Essence becomes the first song.
    // The links now run fourth -> first -> second -> third -> nullptr.

    // 5. Start at head and print a song during each pass through the display loop.
    Node* current = head;

   while (current != nullptr) {
        // Use -> to read the title and minutes from the song current points to.
    cout << current->title << " - "
         << current->minutes << " min" << endl;

        current = current->next; // Follow the link to the next song.

       // 6. Restart at head for Part 5 (6 marks) and count songs and minutes in one pass.
       int songs = 0;
       int total = 0;

       current = head;

       while (current != nullptr) {
        songs++;                   // Count the current song.
        total += current->minutes;  // Add its duration to the total.
        current = current->next;    // Move to the next node.
       }

       // 7. Print the totals for the whole playlist, 4 songs and 16 minutes.
       cout << "Songs: " << songs << endl;
       cout << "Total minutes: " << total << endl;

    // 8. This return is inside the display loop, so only one song is printed.
    return 0;
   }

    


}