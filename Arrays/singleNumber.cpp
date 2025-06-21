#include <iostream>
#include <vector>

using namespace std;

// Function to find the single number where every other element appears twice
int singleNumber(vector<int>& nums) {
    int ans = 0;  // Initialize to 0 before XOR operation
    for (int i = 0; i < nums.size(); i++) {
        ans ^= nums[i];  // XOR cancels out duplicate numbers
    }
    return ans;
}

// Helper function to print a vector (optional)
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Example input: Every number appears twice except one
    vector<int> nums = {2, 3, 5, 4, 5, 3, 4};

    cout << "Input array: ";
    printArray(nums);

    int result = singleNumber(nums);

    cout << "The single number is: " << result << endl;

    return 0;
}
