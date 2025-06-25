#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size(), n = mat[0].size();

        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (target == mat[r][c]) {
                return true;
            } else if (target < mat[r][c]) {
                c--;
            } else {
                r++;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    bool found = solution.searchMatrix(matrix, target);

    if (found)
        cout << "Target " << target << " found in the matrix." << endl;
    else
        cout << "Target " << target << " not found in the matrix." << endl;

    return 0;
}
