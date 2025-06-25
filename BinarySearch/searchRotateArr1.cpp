#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] == nums[left]) {
                left++;
                continue;
            }

            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    bool found = sol.search(nums, target);

    if (found) {
        cout << "Target found in the array." << endl;
    } else {
        cout << "Target not found in the array." << endl;
    }

    return 0;
}
