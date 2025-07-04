#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to rotate the array
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;  // Handle cases where k > n
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

// Helper function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original array: ";
    printArray(nums);

    rotate(nums, k);

    cout << "Rotated array: ";
    printArray(nums);

    return 0;
}
