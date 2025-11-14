#include <iostream>
using namespace std;

struct SongNode {
    string songName;
    string artistName;
    SongNode* prevSong;
    SongNode* nextSong;
};

int main() {
    //enter name and song
    string name, song, choice;
    int pos;
    cout << "enter artist name: ";
    cin >> name;
    cout << "enter name of song: ";
    cin >> song;

    //start with first node
    SongNode* head = new SongNode{name, song, nullptr, nullptr};
    SongNode* index = head;

    while (true) {
        //print out current playlist
        cout << "\ncurrent playlist:\n";
        //iterate index to the start
        index = head;
        while (index != nullptr) {
            cout << "Artist: " << index->artistName << ", Song: " << index->songName << endl;
            index = index->nextSong;
        }

        cout << "do you want to add another song? yes or no\n";
        cin >> choice;
        if (choice == "yes") {
            //where to add
            cout << "where do you want to add it? input number: ";
            cin >> pos;
            //change position to be 0-indexed
            pos--;
            //song details
            cout << "enter artist name: ";
            cin >> name;
            cout << "enter name of song: ";
            cin >> song;

            SongNode* newSong = new SongNode{name, song, nullptr, nullptr};

            if (pos == 0) {
                //insert at head
                newSong->nextSong = head;
                head->prevSong = newSong;
                head = newSong;
            } else {
                //insert at position
                index = head;
                // traverse to position
                for (int i = 0; i < pos - 1 && index->nextSong != nullptr; i++) {
                    index = index->nextSong;
                }
                // insert newSong after index
                newSong->nextSong = index->nextSong;
                // update prev pointer of nextSong
                newSong->prevSong = index;
                // update prev pointer of nextSong if it exists
                if (index->nextSong != nullptr) {
                    index->nextSong->prevSong = newSong;
                }
                // update next pointer of index
                index->nextSong = newSong;
            }
        } else {
            // print final playlist and exit
            cout << "\nfinal playlist:\n";
            index = head;
            while (index != nullptr) {
                cout << "Artist: " << index->artistName << ", Song: " << index->songName << endl;
                index = index->nextSong;
            }
            break;
        }
    }
    return 0;
}