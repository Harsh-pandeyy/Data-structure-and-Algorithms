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
    vector<int> nums;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        nums.push_back(x);
    }

    bool result = check(nums);
    cout << (result ? "true" : "false") << endl;
    return 0;
}

/*
Summary:
Reads an array from user input and checks if it is a rotated sorted array.
The check function counts how many times the order breaks (nums[i-1] > nums[i]).
Also considers the rotation boundary (last element > first element).
Returns true if there's at most one such break.
*/
