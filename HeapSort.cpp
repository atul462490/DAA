#include <iostream>
#include <vector>

using namespace std;

int comparisons = 0;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        comparisons++;
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        comparisons++;
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter array elements\n";
        cout << "2. Display original array\n";
        cout << "3. Sort using Heap Sort and display\n";
        cout << "4. Number of comparisons\n";
        cout << "5. Exit\n";
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
                for (int num : arr) {
                    cout << num << " ";
                }
                cout << endl;
                break;
            case 3:
                heapSort(arr);
                cout << "Sorted array using Heap Sort: ";
                for (int num : arr) {
                    cout << num << " ";
                }
                cout << endl;
                break;
            case 4:
                cout << "Number of comparisons: " << comparisons << endl;
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
