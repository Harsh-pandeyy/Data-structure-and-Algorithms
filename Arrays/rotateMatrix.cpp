#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

void rotate(vector<vector<int>>& mat) {
    int n = mat.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]); // Transpose
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end()); // Reverse each row
    }
}

// Helper function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    rotate(matrix);

    cout << "\nRotated Matrix:\n";
    printMatrix(matrix);

    return 0;
}
