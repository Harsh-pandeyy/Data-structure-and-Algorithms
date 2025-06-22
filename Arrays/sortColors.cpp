#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortColors(vector<int>& nums) {
    int red = 0;
    int white = 0;
    int blue = nums.size() - 1;

    while (white <= blue) {
        if (nums[white] == 0) {
            swap(nums[white], nums[red]);
            red++;
            white++;
        } else if (nums[white] == 1) {
            white++;
        } else {
            swap(nums[white], nums[blue]);
            blue--;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    sortColors(nums);

    cout << "Sorted Colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
