#include <iostream>
#include <vector>

using namespace std;

int merge(vector<int>& arr, int left, int mid, int right) {
    int comparisons = 0;

    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        comparisons++;
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

    return comparisons;
}

int mergeSort(vector<int>& arr, int left, int right) {
    int comparisons = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        comparisons += mergeSort(arr, left, mid);
        comparisons += mergeSort(arr, mid + 1, right);

        comparisons += merge(arr, left, mid, right);
    }
    return comparisons;
}

int main() {
    // Example usage:
    vector<int> arr = {12, 11, 13, 5, 6};
    int comparison_count = mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }

    cout << "\nNumber of comparisons: " << comparison_count << endl;

    return 0;
}
