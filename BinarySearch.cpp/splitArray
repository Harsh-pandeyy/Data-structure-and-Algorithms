#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int check(int mid, vector<int>& nums) {
    int cnt = 0;
    int curr = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (curr + nums[i] < mid) {
            curr += nums[i];
        } else {
            cnt++;
            curr = nums[i];
        }
    }
    cnt++;
    return cnt;
}

int splitArray(vector<int>& nums, int k) {
    int sum = 0;
    int maxi = INT_MIN;

    for (auto i : nums) {
        sum += i;
        maxi = max(maxi, i);
    }

    if (k == 1)
        return sum;
    if (k == nums.size())
        return maxi;

    int low = maxi;
    int high = sum;
    int ans = maxi;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (check(mid, nums) > k) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {7, 2, 5, 10, 8};  // Example input
    int k = 2;

    int result = splitArray(nums, k);
    cout << "The minimized largest sum among " << k << " subarrays is: " << result << endl;

    return 0;
}
