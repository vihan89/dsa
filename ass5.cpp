#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title;
    int duration;
    Node* next;
};

Node* head = NULL;
Node* current = NULL;

// Add song at end
void addSong(string title, int duration) {
    Node* n = new Node{title, duration, NULL};

    if (head == NULL) {
        head = n;
        n->next = n;      // circular
        current = head;
    }
    else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }
    cout << "Added: " << title << "\n";
}

// Delete a song by title
void deleteSong(string title) {
    if (head == NULL) {
        cout << "Playlist empty.\n";
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    do {
        if (temp->title == title) {

            // Case: only 1 song
            if (temp == head && temp->next == head) {
                delete temp;
                head = NULL;
                current = NULL;
                cout << "Deleted last song.\n";
                return;
            }

            // Case: deleting head
            if (temp == head) {
                Node* last = head;
                while (last->next != head)
                    last = last->next;
                head = head->next;
                last->next = head;
                if (current == temp) current = head;
                delete temp;
                cout << "Deleted: " << title << "\n";
                return;
            }

            // Case: middle or last node
            prev->next = temp->next;
            if (current == temp) current = temp->next;
            delete temp;
            cout << "Deleted: " << title << "\n";
            return;
        }

        prev = temp;
        temp = temp->next;
    }
    while (temp != head);

    cout << "Song not found.\n";
}

// Move to next song
void nextSong() {
    if (current == NULL) {
        cout << "Playlist empty.\n";
        return;
    }
    current = current->next;
    cout << "Now playing: " << current->title 
         << " (" << current->duration << "s)\n";
}

// Show all songs
void showPlaylist() {
    if (head == NULL) {
        cout << "Playlist empty.\n";
        return;
    }

    cout << "\n--- Playlist ---\n";
    Node* temp = head;
    do {
        cout << temp->title << " (" << temp->duration << "s)\n";
        temp = temp->next;
    }
    while (temp != head);
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Add Song\n2. Delete Song\n3. Next Song\n4. Show Playlist\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string t;
            int d;
            cout << "Enter title: ";
            getline(cin, t);
            cout << "Enter duration: ";
            cin >> d;
            cin.ignore();
            addSong(t, d);
        }
        else if (choice == 2) {
            string t;
            cout << "Enter song title to delete: ";
            getline(cin, t);
            deleteSong(t);
        }
        else if (choice == 3) nextSong();
        else if (choice == 4) showPlaylist();
        else if (choice == 5) break;
        else cout << "Invalid option.\n";
    }
}
