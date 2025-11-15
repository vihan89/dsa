#include <iostream>
#include <queue>
using namespace std;

#define MAX 100   // maximum number of people

int graph[MAX][MAX];  // adjacency matrix
int persons = 0;      // count of people added

// Add new person
void addPerson() {
    if (persons >= MAX) {
        cout << "Maximum limit reached.\n";
        return;
    }

    // Initialize new row and column to 0
    for (int i = 0; i <= persons; i++) {
        graph[persons][i] = 0;
        graph[i][persons] = 0;
    }

    cout << "Person " << persons << " added.\n";
    persons++;
}

// Add friendship (undirected)
void addFriendship(int a, int b) {
    if (a >= persons || b >= persons) {
        cout << "Invalid ID.\n";
        return;
    }
    graph[a][b] = 1;
    graph[b][a] = 1;
    cout << "Friendship added.\n";
}

// BFS traversal
void BFS(int start) {
    if (start >= persons) {
        cout << "Invalid ID.\n";
        return;
    }

    bool visited[MAX] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS from " << start << ": ";

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int i = 0; i < persons; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// DFS utility
bool DFS_util(int curr, int target, bool visited[]) {
    if (curr == target) return true;

    visited[curr] = true;

    for (int i = 0; i < persons; i++) {
        if (graph[curr][i] == 1 && !visited[i]) {
            if (DFS_util(i, target, visited))
                return true;
        }
    }
    return false;
}

// DFS wrapper
void DFS(int a, int b) {
    bool visited[MAX] = {false};

    if (DFS_util(a, b, visited))
        cout << "Connection exists!\n";
    else
        cout << "No connection.\n";
}

// Display adjacency matrix
void display() {
    cout << "\nSocial Network (Adjacency Matrix):\n";

    for (int i = 0; i < persons; i++) {
        cout << i << ": ";
        for (int j = 0; j < persons; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, a, b;

    while (true) {
        cout << "\n1. Add Person\n2. Add Friendship\n3. BFS\n4. DFS\n5. Display\n6. Exit\n";
        cin >> choice;

        if (choice == 1) addPerson();
        else if (choice == 2) {
            cin >> a >> b;
            addFriendship(a, b);
        }
        else if (choice == 3) {
            cin >> a;
            BFS(a);
        }
        else if (choice == 4) {
            cin >> a >> b;
            DFS(a, b);
        }
        else if (choice == 5) display();
        else if (choice == 6) break;
    }
    return 0;
}
