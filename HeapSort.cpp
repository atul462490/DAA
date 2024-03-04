#include <iostream>
#include <vector>
using namespace std;

// Function to heapify a subtree rooted at node 'index' in the vector 'arr' of size 'n'
void heapify(vector<int>& arr, int n, int index, int& comparisons) {
    int largest = index; // Initialize largest as root
    int left = 2 * index + 1; // left = 2*index + 1
    int right = 2 * index + 2; // right = 2*index + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != index) {
        swap(arr[index], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, comparisons);
    }
    comparisons++;
}

// Function to perform Heap Sort
void heapSort(vector<int>& arr, int& comparisons) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0, comparisons);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int comparisons = 0; // Variable to count the number of comparisons
    heapSort(arr, comparisons);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nNumber of comparisons: " << comparisons << endl;

    return 0;
}
