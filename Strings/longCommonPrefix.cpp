#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    sort(strs.begin(), strs.end());
    int n = strs.size();
    string ans = "";
    string first = strs[0];
    string last = strs[n - 1];
    int i = 0;

    while (i < first.size() && first[i] == last[i]) {
        ans += first[i];
        i++;
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);
    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
    }

    string result = longestCommonPrefix(strs);
    cout << "Longest common prefix: " << result << endl;

    return 0;
}
