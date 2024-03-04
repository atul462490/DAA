#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
void matrixAddition(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void matrixSubtraction(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to multiply two matrices using Strassen's algorithm
void strassenMultiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& result) {
    int n = A.size();

    // Base case: If the matrix size is 1x1
    if (n == 1) {
        result[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Divide matrices into quadrants
    vector<vector<int>> A11(n / 2, vector<int>(n / 2));
    vector<vector<int>> A12(n / 2, vector<int>(n / 2));
    vector<vector<int>> A21(n / 2, vector<int>(n / 2));
    vector<vector<int>> A22(n / 2, vector<int>(n / 2));

    vector<vector<int>> B11(n / 2, vector<int>(n / 2));
    vector<vector<int>> B12(n / 2, vector<int>(n / 2));
    vector<vector<int>> B21(n / 2, vector<int>(n / 2));
    vector<vector<int>> B22(n / 2, vector<int>(n / 2));

    vector<vector<int>> C11(n / 2, vector<int>(n / 2));
    vector<vector<int>> C12(n / 2, vector<int>(n / 2));
    vector<vector<int>> C21(n / 2, vector<int>(n / 2));
    vector<vector<int>> C22(n / 2, vector<int>(n / 2));

    // Initialize the quadrants
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n / 2];
            A21[i][j] = A[i + n / 2][j];
            A22[i][j] = A[i + n / 2][j + n / 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n / 2];
            B21[i][j] = B[i + n / 2][j];
            B22[i][j] = B[i + n / 2][j + n / 2];
        }
    }

    // Recursive steps
    vector<vector<int>> P1(n / 2, vector<int>(n / 2));
    vector<vector<int>> P2(n / 2, vector<int>(n / 2));
    vector<vector<int>> P3(n / 2, vector<int>(n / 2));
    vector<vector<int>> P4(n / 2, vector<int>(n / 2));
    vector<vector<int>> P5(n / 2, vector<int>(n / 2));
    vector<vector<int>> P6(n / 2, vector<int>(n / 2));
    vector<vector<int>> P7(n / 2, vector<int>(n / 2));

    matrixSubtraction(B12, B22, P1);
    strassenMultiplication(A11, P1, C11);

    matrixAddition(A11, A12, P2);
    strassenMultiplication(P2, B22, C12);

    matrixAddition(A21, A22, P3);
    strassenMultiplication(P3, B11, C21);

    matrixSubtraction(B21, B11, P4);
    strassenMultiplication(A22, P4, C22);

    matrixAddition(A11, A22, P5);
    matrixAddition(B11, B22, P6);
    strassenMultiplication(P5, P6, C11);

    matrixSubtraction(A12, A22, P7);
    matrixAddition(B21, B22, P1);
    strassenMultiplication(P7, P1, C21);

    matrixAddition(A11, A12, P2);
    matrixSubtraction(B12, B11, P4);
    matrixAddition(P2, P4, P5);
    strassenMultiplication(P5, A22, C22);

    matrixSubtraction(A21, A11, P3);
    matrixAddition(B11, B12, P6);
    matrixAddition(P3, P6, P7);
    strassenMultiplication(P7, B22, C12);

    // Combine results into the result matrix
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + n / 2] = C12[i][j];
            result[i + n / 2][j] = C21[i][j];
            result[i + n / 2][j + n / 2] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrixA, matrixB, result;
    int n;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enter matrix A\n";
        cout << "2. Enter matrix B\n";
        cout << "3. Multiply matrices using Strassen's algorithm\n";
        cout << "4. Display result matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the size of matrices (n x n): ";
                cin >> n;
                matrixA.resize(n, vector<int>(n));
                cout << "Enter matrix A elements:\n";
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        cin >> matrixA[i][j];
                    }
                }
                break;
            case 2:
                cout << "Enter matrix B elements:\n";
                matrixB.resize(n, vector<int>(n));
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        cin >> matrixB[i][j];
                    }
                }
                break;
            case 3:
                result.resize(n, vector<int>(n, 0));
                strassenMultiplication(matrixA, matrixB, result);
                cout << "Matrices multiplied using Strassen's algorithm.\n";
                break;
            case 4:
                cout << "Result matrix:\n";
                printMatrix(result);
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
