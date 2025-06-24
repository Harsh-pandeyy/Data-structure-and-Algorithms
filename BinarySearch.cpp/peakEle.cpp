#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return 0;

    if (nums[0] > nums[1])
        return 0;
    if (nums[n - 1] > nums[n - 2])
        return n - 1;

    int l = 1, h = n - 2;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;
        else if (nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};  // Example input
    int peakIndex = findPeakElement(nums);
    
    if (peakIndex != -1)
        cout << "Peak element is at index " << peakIndex << " with value " << nums[peakIndex] << endl;
    else
        cout << "No peak element found." << endl;

    return 0;
}
