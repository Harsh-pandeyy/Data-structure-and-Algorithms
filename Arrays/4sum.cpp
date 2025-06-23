#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int tar) {
    vector<vector<int>> ans;
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++) {
        // Skip duplicates for the first number
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; ) {
            int p = j + 1, q = n - 1;

            while (p < q) {
                // Use long long to avoid integer overflow
                long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                if (sum < tar) {
                    p++;
                } else if (sum > tar) {
                    q--;
                } else {
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;

                    // Skip duplicates for third number
                    while (p < q && nums[p] == nums[p - 1])
                        p++;
                    // Skip duplicates for fourth number
                    while (p < q && nums[q] == nums[q + 1])
                        q--;
                }
            }

            j++;
            // Skip duplicates for second number
            while (j < n && nums[j] == nums[j - 1])
                j++;
        }
    }

    return ans;
}
