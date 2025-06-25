#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    // Ensure nums1 is the smaller array
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int low = 0, high = n1;
    int combinedHalfLength = (n1 + n2 + 1) / 2;

    while (low <= high) {
        int partition1 = (low + high) / 2;
        int partition2 = combinedHalfLength - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
        int minRight1 = (partition1 == n1) ? INT_MAX : nums1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
        int minRight2 = (partition2 == n2) ? INT_MAX : nums2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((n1 + n2) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            high = partition1 - 1;
        } else {
            low = partition1 + 1;
        }
    }

    return -1.0;  // Should not reach here for valid inputs
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "The median is: " << median << endl;

    return 0;
}
