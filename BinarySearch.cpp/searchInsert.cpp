#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] > target) {
            right = mid - 1; // Search left
        } else {
            left = mid + 1; // Search right
        }
    }

    // Target not found, return insert position
    return left;
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int index = searchInsert(nums, target);
    std::cout << "Insert position: " << index << std::endl;

    return 0;
}
