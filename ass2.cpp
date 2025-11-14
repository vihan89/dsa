#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

int main() {

    // ================================
    // 1) VECTOR
    // ================================
    cout << "\n===== VECTOR =====\n";
    vector<int> v = {10, 20, 30};

    // Access
    cout << "Front: " << v.front() << "\n";
    cout << "Back: " << v.back() << "\n";
    cout << "At(1): " << v.at(1) << "\n";

    // Alter
    v[1] = 200;

    // Insert
    v.push_back(40);

    // Delete
    v.pop_back(); // deletes 40

    // Loop through
    cout << "Vector Elements: ";
    for (int x : v) cout << x << " ";
    cout << "\n";


    // ================================
    // 2) LIST (doubly linked list)
    // ================================
    cout << "\n===== LIST =====\n";
    list<int> li = {5, 10, 15};

    // Access
    cout << "Front: " << li.front() << "\n";
    cout << "Back: " << li.back() << "\n";

    // Alter
    li.front() = 50; // modifying front

    // Insert
    li.push_back(20);
    li.push_front(1);

    // Delete
    li.pop_back();
    li.pop_front();

    // Loop through
    cout << "List Elements: ";
    for (int x : li) cout << x << " ";
    cout << "\n";


    // ================================
    // 3) STACK (LIFO)
    // ================================
    cout << "\n===== STACK =====\n";
    stack<int> st;

    // Insert (push)
    st.push(100);
    st.push(200);
    st.push(300);

    // Access (top)
    cout << "Top: " << st.top() << "\n";

    // Alter (pop changes top)
    st.pop(); // removes 300

    // Loop through (pop all)
    cout << "Stack Elements: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";


    // ================================
    // 4) QUEUE (FIFO)
    // ================================
    cout << "\n===== QUEUE =====\n";
    queue<int> q;

    // Insert
    q.push(11);
    q.push(22);
    q.push(33);

    // Access
    cout << "Front: " << q.front() << "\n";
    cout << "Back: " << q.back() << "\n";

    // Alter (pop changes front)
    q.pop();

    // Loop through (pop all)
    cout << "Queue Elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";


    // ================================
    // 5) SET (unique + sorted)
    // ================================
    cout << "\n===== SET =====\n";
    set<int> s;

    // Insert
    s.insert(30);
    s.insert(10);
    s.insert(20);
    s.insert(10); // duplicate, ignored

    // Loop through
    cout << "Set Elements (sorted & unique): ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    // Access first element using begin()
    cout << "Smallest element: " << *s.begin() << "\n";

    // Remove
    s.erase(20);

    cout << "After deletion: ";
    for (int x : s) cout << x << " ";
    cout << "\n";


    // ================================
    // 6) MAP (key-value pair)
    // ================================
    cout << "\n===== MAP =====\n";
    map<int, string> mp;

    // Insert
    mp[1] = "Apple";
    mp[2] = "Ball";
    mp[3] = "Cat";

    // Access
    cout << "Key 2 → " << mp[2] << "\n";

    // Alter
    mp[2] = "Banana";

    // Loop through
    cout << "Map Elements:\n";
    for (auto p : mp) {
        cout << p.first << " -> " << p.second << "\n";
    }

    // Delete
    mp.erase(1);

    cout << "After delete:\n";
    for (auto p : mp) {
        cout << p.first << " -> " << p.second << "\n";
    }

    return 0;
}
