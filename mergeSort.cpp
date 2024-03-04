#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int left, int middle, int right, int& comparisons) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;
    int inversions = 0;

    while (i < n1 && j < n2) {
        comparisons++; // Counting comparisons
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            inversions += n1 - i;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    return inversions;
}

int mergeSort(vector<int>& arr, int left, int right, int& comparisons) {
    int inversions = 0;
    if (left < right) {
        int middle = left + (right - left) / 2;

        inversions += mergeSort(arr, left, middle, comparisons);
        inversions += mergeSort(arr, middle + 1, right, comparisons);

        inversions += merge(arr, left, middle, right, comparisons);
    }
    return inversions;
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int comparisons = 0;
    int inversions = mergeSort(arr, 0, n - 1, comparisons);

    cout << "Sorted array: ";
    printArray(arr);
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of inversions: " << inversions << endl;

    return 0;
}
