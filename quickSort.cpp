#include <iostream>
#include <vector>

using namespace std;

// Function to partition the array and return the index of the pivot element
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform the Quick Sort algorithm
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the two halves
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter array elements\n";
        cout << "2. Display original array\n";
        cout << "3. Sort using Quick Sort and display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int n;
                cout << "Enter the number of elements: ";
                cin >> n;
                arr.resize(n);
                cout << "Enter the elements: ";
                for (int i = 0; i < n; ++i) {
                    cin >> arr[i];
                }
                break;
            case 2:
                cout << "Original array: ";
                printArray(arr);
                break;
            case 3:
                quickSort(arr, 0, arr.size() - 1);
                cout << "Sorted array using Quick Sort: ";
                printArray(arr);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
