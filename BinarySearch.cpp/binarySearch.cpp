#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] < target) {
            left = mid + 1; // Search right
        } else {
            right = mid - 1; // Search left
        }
    }

    return -1; // Target not found
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int index = search(nums, target);
    
    if (index != -1) {
        std::cout << "Target found at index: " << index << std::endl;
    } else {
        std::cout << "Target not found." << std::endl;
    }

    return 0;
}
