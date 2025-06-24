#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if (n == 1 || nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];
    int s = 1;
    int e = nums.size() - 2;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        if (mid % 2 == 0) {
            if (nums[mid] == nums[mid + 1]) {
                s = mid + 2;
            } else {
                e = mid - 1;
            }
        } else {
            if (nums[mid] == nums[mid - 1]) {
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }
    return nums[s];
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    cout << "Single non-duplicate element: " << singleNonDuplicate(nums) << endl;
    return 0;
}
