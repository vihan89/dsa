#include <iostream>
#include <stack>
using namespace std;

class Student {
public:
    int roll;
    string name;
    int marks;
    Student *left, *right;

    Student(int r, string n, int m) {
        roll = r;
        name = n;
        marks = m;
        left = right = NULL;
    }
};

class BST {
private:
    Student* root;

    // Create a new node
    Student* createNode(int r, string n, int m) {
        return new Student(r, n, m);
    }

    // INSERT (recursive)
    Student* insertRec(Student* node, int r, string n, int m) {
        if (!node) return createNode(r, n, m);

        if (r < node->roll)
            node->left = insertRec(node->left, r, n, m);
        else if (r > node->roll)
            node->right = insertRec(node->right, r, n, m);
        else
            cout << "Duplicate roll number not allowed.\n";

        return node;
    }

    // SEARCH (recursive)
    Student* searchRec(Student* node, int r) {
        if (!node) return NULL;

        if (r == node->roll) return node;
        else if (r < node->roll) return searchRec(node->left, r);
        else return searchRec(node->right, r);
    }

    // FIND MIN node
    Student* findMin(Student* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // DELETE node
    Student* deleteRec(Student* node, int r) {
        if (!node) return NULL;

        if (r < node->roll)
            node->left = deleteRec(node->left, r);
        else if (r > node->roll)
            node->right = deleteRec(node->right, r);
        else {
            if (!node->left) {
                Student* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Student* temp = node->left;
                delete node;
                return temp;
            }

            Student* temp = findMin(node->right);
            node->roll = temp->roll;
            node->name = temp->name;
            node->marks = temp->marks;

            node->right = deleteRec(node->right, temp->roll);
        }

        return node;
    }

    //
    // RECURSIVE TRAVERSALS
    //
    void inorderRec(Student* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->roll << " | " << node->name << " | " << node->marks << endl;
        inorderRec(node->right);
    }

    void preorderRec(Student* node) {
        if (!node) return;
        cout << node->roll << " | " << node->name << " | " << node->marks << endl;
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void postorderRec(Student* node) {
        if (!node) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->roll << " | " << node->name << " | " << node->marks << endl;
    }

    //
    // FIND MAX MARKS
    //
    Student* findMaxMarksRec(Student* node) {
        if (!node) return NULL;
        Student* left = findMaxMarksRec(node->left);
        Student* right = findMaxMarksRec(node->right);

        Student* maxNode = node;
        if (left && left->marks > maxNode->marks) maxNode = left;
        if (right && right->marks > maxNode->marks) maxNode = right;

        return maxNode;
    }

    //
    // FIND MIN MARKS
    //
    Student* findMinMarksRec(Student* node) {
        if (!node) return NULL;
        Student* left = findMinMarksRec(node->left);
        Student* right = findMinMarksRec(node->right);

        Student* minNode = node;
        if (left && left->marks < minNode->marks) minNode = left;
        if (right && right->marks < minNode->marks) minNode = right;

        return minNode;
    }

    //
    // COUNT nodes
    //
    int countNodesRec(Student* node) {
        if (!node) return 0;
        return 1 + countNodesRec(node->left) + countNodesRec(node->right);
    }

public:
    BST() {
        root = NULL;
    }

    // Public wrapper methods
    void insert(int r, string n, int m) {
        root = insertRec(root, r, n, m);
    }

    void deleteNode(int r) {
        root = deleteRec(root, r);
    }

    Student* search(int r) {
        return searchRec(root, r);
    }

    //
    // RECURSIVE TRAVERSAL WRAPPERS
    //
    void inorder() { inorderRec(root); }
    void preorder() { preorderRec(root); }
    void postorder() { postorderRec(root); }

    //
    // NON-RECURSIVE TRAVERSALS
    //
    void inorderNR() {
        stack<Student*> st;
        Student* curr = root;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); st.pop();
            cout << curr->roll << " | " << curr->name << " | " << curr->marks << endl;
            curr = curr->right;
        }
    }

    void preorderNR() {
        if (!root) return;
        stack<Student*> st;
        st.push(root);

        while (!st.empty()) {
            Student* curr = st.top(); st.pop();
            cout << curr->roll << " | " << curr->name << " | " << curr->marks << endl;

            if (curr->right) st.push(curr->right);
            if (curr->left)  st.push(curr->left);
        }
    }

    void postorderNR() {
        if (!root) return;
        stack<Student*> s1, s2;

        s1.push(root);
        while (!s1.empty()) {
            Student* curr = s1.top(); s1.pop();
            s2.push(curr);

            if (curr->left)  s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }

        while (!s2.empty()) {
            Student* curr = s2.top(); s2.pop();
            cout << curr->roll << " | " << curr->name << " | " << curr->marks << endl;
        }
    }

    //
    // MARKS HELPERS
    //
    Student* getMaxMarks() { return findMaxMarksRec(root); }
    Student* getMinMarks() { return findMinMarksRec(root); }
    int countStudents() { return countNodesRec(root); }
};

//
// MAIN PROGRAM
//
int main() {
    BST tree;
    int choice;

    while (true) {
        cout << "\n--- Student BST Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n";
        cout << "4. Inorder (R)\n5. Preorder (R)\n6. Postorder (R)\n";
        cout << "7. Inorder (NR)\n8. Preorder (NR)\n9. Postorder (NR)\n";
        cout << "10. Highest Marks\n11. Lowest Marks\n12. Total Students\n13. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int r, m;
            string n;
            cout << "Enter Roll, Name, Marks: ";
            cin >> r >> n >> m;
            tree.insert(r, n, m);
        }
        else if (choice == 2) {
            int r;
            cout << "Enter roll to delete: ";
            cin >> r;
            tree.deleteNode(r);
        }
        else if (choice == 3) {
            int r;
            cout << "Enter roll to search: ";
            cin >> r;
            Student* s = tree.search(r);
            if (s)
                cout << "Found: " << s->roll << " | " << s->name << " | " << s->marks << endl;
            else
                cout << "Not found.\n";
        }
        else if (choice == 4) tree.inorder();
        else if (choice == 5) tree.preorder();
        else if (choice == 6) tree.postorder();
        else if (choice == 7) tree.inorderNR();
        else if (choice == 8) tree.preorderNR();
        else if (choice == 9) tree.postorderNR();
        else if (choice == 10) {
            Student* s = tree.getMaxMarks();
            if (s) cout << "Highest Marks: " << s->name << " (" << s->marks << ")\n";
        }
        else if (choice == 11) {
            Student* s = tree.getMinMarks();
            if (s) cout << "Lowest Marks: " << s->name << " (" << s->marks << ")\n";
        }
        else if (choice == 12) {
            cout << "Total Students: " << tree.countStudents() << endl;
        }
        else if (choice == 13) break;
    }

    return 0;
}
