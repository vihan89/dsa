#include <iostream>
using namespace std;

// Safe integer input function (prevents infinite loop)
int getInt() {
    int x;
    while (true) {
        if (cin >> x) {
            cin.ignore(1000000, '\n'); // clear extra characters
            return x;
        }
        cin.clear();
        cin.ignore(1000000, '\n');
        cout << "Invalid input! Enter a number: ";
    }
}

// Print array
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

// Bubble Sort
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}

// Quick Sort
int partition(int a[], int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Merge Sort
void merge(int a[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[50], R[50];

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

// Linear Search
int linearSearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (a[i] == key) return i;
    return -1;
}

// Binary Search
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, a[50];

    cout << "Enter number of elements: ";
    n = getInt();

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        a[i] = getInt();

    while (true) {
        cout << "\nMENU\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Quick Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Linear Search\n";
        cout << "5. Binary Search\n";
        cout << "6. Print Array\n";
        cout << "7. Exit\n";
        cout << "Choose: ";

        int ch = getInt();

        if (ch == 7) {
            cout << "Exiting program...\n";
            break;
        }

        switch (ch) {
            case 1:
                bubbleSort(a, n);
                cout << "Bubble Sorted Array:\n";
                printArray(a, n);
                break;

            case 2:
                quickSort(a, 0, n - 1);
                cout << "Quick Sorted Array:\n";
                printArray(a, n);
                break;

            case 3:
                mergeSort(a, 0, n - 1);
                cout << "Merge Sorted Array:\n";
                printArray(a, n);
                break;

            case 4: {
                cout << "Enter value to search: ";
                int key = getInt();
                int idx = linearSearch(a, n, key);
                if (idx == -1) cout << "Not found\n";
                else cout << "Found at index " << idx << "\n";
            } break;

            case 5: {
                cout << "Enter value to search: ";
                int key = getInt();
                int idx = binarySearch(a, n, key);
                if (idx == -1) cout << "Not found (array must be sorted!)\n";
                else cout << "Found at index " << idx << "\n";
            } break;

            case 6:
                printArray(a, n);
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
    return 0;
}
