#include <iostream>
#include <vector>
#include <string>
#include <climits>  // For INT_MIN and INT_MAX
#include <algorithm> // For max and min

using namespace std;

// Helper function to calculate beauty of current character frequency map
int solution(const vector<int>& hash) {
    int mf = INT_MIN; // max frequency
    int lf = INT_MAX; // min frequency (ignoring zeros)

    for (int i = 0; i < 26; i++) {
        if (hash[i] > 0) {
            mf = max(mf, hash[i]);
            lf = min(lf, hash[i]);
        }
    }

    return mf - lf;
}

// Main function to compute the beauty sum of all substrings
int beautySum(const string& s) {
    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
        vector<int> hash(26, 0);

        for (int j = i; j < s.size(); j++) {
            hash[s[j] - 'a']++;
            sum += solution(hash);
        }
    }

    return sum;
}

// Optional main() function for testing in Visual Studio
int main() {
    string input = "aabcb";
    cout << "Beauty sum: " << beautySum(input) << endl;
    return 0;
}
