#include <iostream>
#include <vector>
#include <algorithm> // for min_element, max_element

using namespace std;

bool isValid(vector<int>& bloomDay, int m, int k, int mid) {
    int bouquets = 0, flowers = 0;
    for (int day : bloomDay) {
        if (day <= mid) {
            flowers++;
            if (flowers == k) {
                bouquets++;
                flowers = 0;
                if (bouquets >= m) return true;
            }
        } else {
            flowers = 0;
        }
    }
    return false;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if ((long)m * k > bloomDay.size()) return -1;

    int l = *min_element(bloomDay.begin(), bloomDay.end());
    int r = *max_element(bloomDay.begin(), bloomDay.end());

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (isValid(bloomDay, m, k, mid)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    int result = minDays(bloomDay, m, k);
    cout << "Minimum number of days: " << result << endl;

    return 0;
}
