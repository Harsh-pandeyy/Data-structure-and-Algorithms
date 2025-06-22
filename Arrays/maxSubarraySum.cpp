#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& arr) {
    long long sum = 0;
    long long maxi = LLONG_MIN;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    return static_cast<int>(maxi);
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum subarray sum is: " << maxSubArray(nums) << endl;
    return 0;
}
