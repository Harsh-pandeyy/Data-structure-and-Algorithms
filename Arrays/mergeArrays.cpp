#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Merge function: merges nums2 into nums1 in-place
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // Copy elements from nums2 into nums1 starting at index m
    for (int j = 0, i = m; j < n; j++, i++) {
        nums1[i] = nums2[j];
    }

    // Sort the resulting array
    sort(nums1.begin(), nums1.end());
}

int main() {
    // Example input arrays
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    // Call the merge function
    merge(nums1, m, nums2, n);

    // Output the result
    cout << "Merged Array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
