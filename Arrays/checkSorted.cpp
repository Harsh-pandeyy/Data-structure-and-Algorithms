#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& nums) {
    int n = nums.size();
    int cnt = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i - 1] > nums[i]) {
            cnt++;
        }
    }

    if (nums[n - 1] > nums[0]) {
        cnt++;
    }

    return cnt <= 1;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    bool result = check(nums);
    cout << (result ? "true" : "false") << endl;
    return 0;
}

/*
Summary:
This function checks if the array is a rotated sorted array (non-decreasing).
It counts how many times the order breaks (nums[i-1] > nums[i]).
Also checks the last and first element to cover the rotation.
Returns true if there's at most one such break.
*/
