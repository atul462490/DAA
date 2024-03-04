#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& arr) {
    int n = arr.size();

    // Find the maximum element in the array
    int maxNum = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxNum) {
            maxNum = arr[i];
        }
    }

    // Create a count array to store the occurrences of each element
    vector<int> count(maxNum + 1, 0);
    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    // Modify the count array to store the cumulative sum
    for (int i = 1; i <= maxNum; ++i) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted elements
    vector<int> output(n);

    // Build the output array
    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Update the original array with the sorted elements
    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
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
        cout << "3. Sort using Counting Sort and display\n";
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
                countingSort(arr);
                cout << "Sorted array using Counting Sort: ";
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
