#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Otherwise, right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int index = sol.search(nums, target);

    if (index != -1) {
        std::cout << "Target found at index: " << index << std::endl;
    } else {
        std::cout << "Target not found." << std::endl;
    }

    return 0;
}
