#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int l = 1;
    int maxi = *max_element(nums.begin(), nums.end());

    if (n == threshold)
        return maxi;

    int ans = maxi;

    while (l <= maxi) {
        int mid = (l + maxi) / 2;
        int sum = 0;

        for (int it : nums) {
            sum += (it + mid - 1) / mid; // Equivalent to ceil(it / mid)
        }

        if (sum <= threshold) {
            ans = mid;
            maxi = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 2, 5, 9};  // Example input
    int threshold = 6;

    int result = smallestDivisor(nums, threshold);
    cout << "Smallest Divisor: " << result << endl;

    return 0;
}
