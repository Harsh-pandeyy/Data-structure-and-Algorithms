#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    for (auto it : intervals) {
        if (ans.empty() || ans.back()[1] < it[0]) {
            ans.push_back(it);
        } else {
            ans.back()[1] = max(ans.back()[1], it[1]);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> merged = merge(intervals);

    cout << "Merged intervals:\n";
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}
