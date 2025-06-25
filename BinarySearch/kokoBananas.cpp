#include <iostream>
#include <vector>
#include <cmath>     // For ceil
#include <climits>   // For INT_MAX, INT_MIN
#include <algorithm> // For min, max

using namespace std;

bool isPossible(vector<int>& piles, int h, int currHr) {
    int hrCnt = 0;
    for (int i = 0; i < piles.size(); i++) {
        if (piles[i] <= currHr)
            hrCnt++;
        else
            hrCnt += ceil((double)piles[i] / (double)currHr);

        if (hrCnt > h) return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        maxi = max(maxi, piles[i]);
    }

    if (n == h) return maxi;

    int low = 1;
    int high = maxi;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(piles, h, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int result = minEatingSpeed(piles, h);
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
