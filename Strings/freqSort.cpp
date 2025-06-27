#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string frequencySort(string s) {
    vector<pair<int, char>> hash('z' + 1, {0, 0});
    for (char c : s) {
        hash[c].first++;
        hash[c].second = c;
    }
    sort(hash.begin(), hash.end());
    string res = "";
    for (auto p : hash) {
        res = string(p.first, p.second) + res;
    }
    return res;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string result = frequencySort(input);
    cout << "Sorted by frequency: " << result << endl;

    return 0;
}
