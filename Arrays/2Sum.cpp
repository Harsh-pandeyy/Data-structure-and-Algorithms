#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find two indices whose values sum to the target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numToIndex;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numToIndex.find(complement) != numToIndex.end()) {
            return {numToIndex[complement], i};
        }
        numToIndex[nums[i]] = i;
    }
    return {-1, -1}; // Not found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (result[0] != -1) {
        cout << "Indices: " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No two numbers sum to the target." << endl;
    }

    return 0;
}
