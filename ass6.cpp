#include <iostream>
#include <stack>
using namespace std;

struct Student {
    int roll;
    string name;
    int marks;
    Student *left, *right;
};

Student* root = NULL;

// Create new node
Student* createNode(int r, string n, int m) {
    return new Student{r, n, m, NULL, NULL};
}

// INSERT
Student* insert(Student* node, int r, string n, int m) {
    if (!node) return createNode(r, n, m);

    if (r < node->roll)
        node->left = insert(node->left, r, n, m);
    else if (r > node->roll)
        node->right = insert(node->right, r, n, m);
    else
        cout << "Duplicate roll number not allowed.\n";

    return node;
}

// SEARCH
Student* search(Student* node, int r) {
    if (!node) return NULL;
    
    if (r == node->roll) return node;
    else if (r < node->roll) return search(node->left, r);
    else return search(node->right, r);
}

// FIND MIN NODE — used in delete()
Student* findMin(Student* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// DELETE
Student* deleteNode(Student* node, int r) {
    if (!node) return NULL;

    if (r < node->roll)
        node->left = deleteNode(node->left, r);
    else if (r > node->roll)
        node->right = deleteNode(node->right, r);
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

        node->right = deleteNode(node->right, temp->roll);
    }
    return node;
}

//
// RECURSIVE TRAVERSALS
//
void inorder(Student* node) {
    if (!node) return;
    inorder(node->left);
    cout << node->roll << " | " << node->name << " | " << node->marks << endl;
    inorder(node->right);
}

void preorder(Student* node) {
    if (!node) return;
    cout << node->roll << " | " << node->name << " | " << node->marks << endl;
    preorder(node->left);
    preorder(node->right);
}

void postorder(Student* node) {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->roll << " | " << node->name << " | " << node->marks << endl;
}

//
// NON-RECURSIVE TRAVERSALS
//
void inorderNR(Student* root) {
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

void preorderNR(Student* root) {
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

void postorderNR(Student* root) {
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
// FIND MAX MARKS — simple tree scan
//
Student* findMaxMarks(Student* node) {
    if (!node) return NULL;
    Student* left = findMaxMarks(node->left);
    Student* right = findMaxMarks(node->right);

    Student* maxNode = node;
    if (left && left->marks > maxNode->marks) maxNode = left;
    if (right && right->marks > maxNode->marks) maxNode = right;

    return maxNode;
}

//
// FIND MIN MARKS
//
Student* findMinMarks(Student* node) {
    if (!node) return NULL;
    Student* left = findMinMarks(node->left);
    Student* right = findMinMarks(node->right);

    Student* minNode = node;
    if (left && left->marks < minNode->marks) minNode = left;
    if (right && right->marks < minNode->marks) minNode = right;

    return minNode;
}

//
// COUNT NODES
//
int countNodes(Student* node) {
    if (!node) return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

//
// MAIN MENU
//
int main() {
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
            root = insert(root, r, n, m);
        }
        else if (choice == 2) {
            int r;
            cout << "Enter roll to delete: ";
            cin >> r;
            root = deleteNode(root, r);
        }
        else if (choice == 3) {
            int r;
            cout << "Enter roll to search: ";
            cin >> r;
            Student* s = search(root, r);
            if (s)
                cout << "Found: " << s->roll << " | " << s->name << " | " << s->marks << endl;
            else
                cout << "Not found.\n";
        }
        else if (choice == 4) inorder(root);
        else if (choice == 5) preorder(root);
        else if (choice == 6) postorder(root);
        else if (choice == 7) inorderNR(root);
        else if (choice == 8) preorderNR(root);
        else if (choice == 9) postorderNR(root);
        else if (choice == 10) {
            Student* s = findMaxMarks(root);
            if (s) cout << "Highest Marks: " << s->name << " (" << s->marks << ")\n";
        }
        else if (choice == 11) {
            Student* s = findMinMarks(root);
            if (s) cout << "Lowest Marks: " << s->name << " (" << s->marks << ")\n";
        }
        else if (choice == 12) {
            cout << "Total Students: " << countNodes(root) << endl;
        }
        else if (choice == 13) break;
    }

    return 0;
}
