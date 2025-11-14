#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<string> q;  // only store names to keep it simple

void enqueueCustomer() {
    string name;
    cout << "Enter customer name: ";
    getline(cin, name);
    q.push(name);
    cout << name << " joined the queue.\n";
}

void dequeueCustomer() {
    if (q.empty()) {
        cout << "No customers in queue.\n";
        return;
    }
    cout << q.front() << " got the ticket and left the queue.\n";
    q.pop();
}

void showQueue() {
    if (q.empty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Current queue:\n";
    queue<string> temp = q;
    while (!temp.empty()) {
        cout << temp.front();
        temp.pop();
        if (!temp.empty()) cout << " <- ";
    }
    cout << "\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Enqueue customer\n2. Dequeue customer\n3. Show queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) enqueueCustomer();
        else if (choice == 2) dequeueCustomer();
        else if (choice == 3) showQueue();
        else if (choice == 4) break;
        else cout << "Invalid choice.\n";
    }
    return 0;
}
