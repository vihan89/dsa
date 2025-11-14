#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

vector<vector<int>> graph;   // adjacency list

// Add a new person (new node)
void addPerson() {
    graph.push_back(vector<int>());
    cout << "Person " << graph.size()-1 << " added.\n";
}

// Create friendship (edge)
void addFriendship(int a, int b) {
    if (a >= graph.size() || b >= graph.size()) {
        cout << "Invalid person ID.\n";
        return;
    }
    graph[a].push_back(b);
    graph[b].push_back(a);
    cout << "Friendship added.\n";
}

// BFS – list all friends
void BFS(int start) {
    if (start >= graph.size()) {
        cout << "Invalid ID.\n"; 
        return;
    }

    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS from " << start << ": ";

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int f : graph[node]) {
            if (!visited[f]) {
                visited[f] = true;
                q.push(f);
            }
        }
    }
    cout << endl;
}

// DFS – check if connection exists
bool DFS_util(int curr, int target, vector<bool> &visited) {
    if (curr == target) return true;

    visited[curr] = true;

    for (int f : graph[curr]) {
        if (!visited[f]) {
            if (DFS_util(f, target, visited)) return true;
        }
    }
    return false;
}

void DFS(int a, int b) {
    vector<bool> visited(graph.size(), false);
    if (DFS_util(a, b, visited))
        cout << "Connection exists!\n";
    else
        cout << "No connection.\n";
}

// Display complete graph
void display() {
    cout << "\nSocial Network (Adjacency List):\n";
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (int f : graph[i]) cout << f << " ";
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
}
