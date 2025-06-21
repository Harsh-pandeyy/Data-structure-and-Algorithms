#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to move all zeroes to the end while maintaining the relative order of non-zero elements
void moveZeroes(vector<int>& nums) {
    int left = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] != 0) {
            swap(nums[right], nums[left]);
            left++;
        }
    }
}

// Helper function to print the vector
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original array: ";
    printArray(nums);

    moveZeroes(nums);

    cout << "After moving zeroes: ";
    printArray(nums);

    return 0;
}
