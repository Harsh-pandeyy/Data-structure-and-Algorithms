#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int res = 0;
    int majority = 0;

    for (int n : nums) {
        if (majority == 0) {
            res = n;
        }

        majority += (n == res) ? 1 : -1;
    }

    return res;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority element is: " << majorityElement(nums) << endl;
    return 0;
}
