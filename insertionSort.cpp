#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int insertionSort(vector<int>& arr) {
    int comparisons = 0;
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
            ++comparisons;
        }

        arr[j + 1] = key;
    }

    return comparisons;
}

int main() {
    string input;
    cout << "Enter the elements of the array separated by spaces or commas: ";
    getline(cin, input);

    // Tokenize the input string and convert to integers
    vector<int> arr;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        arr.push_back(num);
        // Check for commas or spaces and ignore them
        if (ss.peek() == ',' || ss.peek() == ' ') {
            ss.ignore();
        }
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display the original array\n";
        cout << "2. Sort the array using Insertion Sort and display\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Original array: ";
                for (int num : arr) {
                    cout << num << " ";
                }
                cout << endl;
                break;
            case 2:
                {
                    vector<int> tempArr = arr;  // Create a copy for sorting
                    int comparison_count = insertionSort(tempArr);
                    cout << "Sorted array using Insertion Sort: ";
                    for (int num : tempArr) {
                        cout << num << " ";
                    }
                    cout << "\nNumber of comparisons: " << comparison_count << endl;
                }
                break;
            case 3:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
