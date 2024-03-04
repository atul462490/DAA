#include <iostream>
#include <vector>

using namespace std;

int comparisons = 0;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            comparisons++; // Increment comparison count
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1); // Recursively sort elements before pivot
        quickSort(arr, pivotIndex + 1, high); // Recursively sort elements after pivot
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
