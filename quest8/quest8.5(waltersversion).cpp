// Walter's Code


#include <iostream>
#include <string>
using namespace std;

// Define the SongNode class
class SongNode {
public:
    string songName;
    string artistName;
    SongNode* prevSong;
    SongNode* nextSong;
};

// Print the playlist
void printList(SongNode* begin) {
    SongNode* cur = begin;
    int i = 1;
    // Iterate through the list and print each song
    while (cur) {
        cout << i << ". \"" << cur->songName << "\"  " << cur->artistName << endl;
        cur = cur->nextSong;
        i++;
    }
}

// Main function
int main() {

    string title, artist;
    cout << "Enter first song title." << endl;
    getline(cin, title);
    cout << "Enter the artist name." << endl;
    getline(cin, artist);

    // Initialize the first node
    SongNode* begin = new SongNode{title, artist, nullptr, nullptr};
    SongNode* end = begin;
    int counter = 1;
    // Print the first song
    cout << "\"" << begin->songName << "\" by " << begin->artistName << endl;

    // Main loop
    while (true) {
        cout << "Do you want to input another song? yes, no, or delete." << endl;
        string answer;
        getline(cin, answer);

        // EXIT LOOP
        if (answer == "no" || answer == "No") {
            break;
        }

        // DELETE SONG
        else if (answer == "delete" || answer == "Delete") {

            if (counter == 0) {
                cout << "Playlist is empty." << endl;
                continue;
            }
            // Display current playlist
            cout << "Which song would you like to delete? Enter the number:" << endl;
            printList(begin);

            // Get index to delete
            int delIndex;
            cin >> delIndex;
            cin.ignore();


            // Validate index
            if (delIndex < 1 || delIndex > counter) {
                cout << "Invalid index." << endl;
                continue;
            }

            // delete first song
            if (delIndex == 1) {
                SongNode* toDelete = begin;
                begin = begin->nextSong;

                if (begin)
                    begin->prevSong = nullptr;
                else
                    end = nullptr;

                delete toDelete;
            }
            // delete last song
            else if (delIndex == counter) {
                SongNode* toDelete = end;
                end = end->prevSong;
                end->nextSong = nullptr;
                delete toDelete;
            }
            // delete middle song
            else {
                SongNode* cur = begin;
                for (int i = 1; i < delIndex; i++)
                    cur = cur->nextSong;

                // add pointer adjustments
                SongNode* before = cur->prevSong;
                SongNode* after = cur->nextSong;

                before->nextSong = after;
                after->prevSong = before;

                delete cur;
            }

            counter--;
            printList(begin);
        }

        // ADD SONG
        else {
            counter++;

            string newTitle, newArtist;
            cout << "Name of song:" << endl;
            getline(cin, newTitle);
            cout << "Artist of song:" << endl;
            getline(cin, newArtist);

            // Create new node
            SongNode* newNode = new SongNode{newTitle, newArtist, nullptr, nullptr};

            cout << "Which spot on the playlist would you like to enter the song? (1 to " << counter << ")" << endl;
            int pos;
            cin >> pos;
            cin.ignore();

            // Validate position
            if (pos < 1 || pos > counter) {
                cout << "Invalid position." << endl;
                counter--;
                delete newNode;
                continue;
            }

            // Insert at start
            if (pos == 1) {
                newNode->prevSong = nullptr;
                newNode->nextSong = begin;
                begin->prevSong = newNode;
                begin = newNode;
            }
            // Insert at end
            else if (pos == counter) {
                newNode->nextSong = nullptr;
                newNode->prevSong = end;
                end->nextSong = newNode;
                end = newNode;
            }
            // Insert in middle
            else {
                SongNode* cur = begin;
                for (int i = 1; i < pos - 1; i++)
                    cur = cur->nextSong;

                newNode->prevSong = cur;
                newNode->nextSong = cur->nextSong;
                cur->nextSong->prevSong = newNode;
                cur->nextSong = newNode;
            }
            // Print updated playlist
            printList(begin);
        }
    }

    return 0;
}



/*
1. How can writing documentation help you understand code better?
The more you're able to understand and decipher your own code, the better you'll be at writing it.

2. How does well-documented code help teams and perhaps open-source communities thrive?
It's nearly impossible for large teams to coordinate and work together without properly documented code, especially for open-source communities.


3. How does contributing to clear documentation reflect social responsibility in the tech industry?
Documenting your code helps others understand your work, allows for others to colloborate, and ensures that others understand the nuances of your code.


4. What are two consequences of bad/no documentation: one in how it impacts you (as if you were the only one who will ever see it), and one how it might negatively impact someone else?
    1. If you leave code even for a bit of time, you can forget how it works, making it harder to pick back up.
    2. If someone else has to work on your code, they may not understand the logic or reasoning behind it.










*/