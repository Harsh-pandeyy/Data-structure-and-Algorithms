#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For accumulate
using namespace std;

class Solution {
    // Helper function to check if capacity x can ship all weights in "days"
    bool func(int x, vector<int>& weights, int days) {
        int c = 1; // number of days used
        int sum = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > x) {
                c++;
                sum = 0;
            }
            sum += weights[i];
        }
        return c <= days;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int ans = 0;
        int l = *max_element(weights.begin(), weights.end()); // min possible capacity
        int r = accumulate(weights.begin(), weights.end(), 0); // max possible capacity

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (func(mid, weights, days)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> weights = {1, 2, 3, 1, 1};
    int days = 4;

    Solution sol;
    int result = sol.shipWithinDays(weights, days);

    cout << "Minimum ship capacity to deliver in " << days << " days is: " << result << endl;
    return 0;
}
