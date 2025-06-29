#include <iostream>
#include <string>
#include <algorithm> // For std::max

using namespace std;

int expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

string longestPalindrome(string s) {
    if (s.empty()) return "";

    int start = 0, maxLength = 0;

    for (int i = 0; i < s.size(); i++) {
        int len1 = expandAroundCenter(s, i - 1, i + 1);
        int len2 = expandAroundCenter(s, i, i + 1);
        int len = max(len1, len2);

        if (maxLength < len) {
            maxLength = len;
            start = i - (len - 1) / 2;
        }
    }

    return s.substr(start, maxLength);
}

// Optional main function for testing in VS
int main() {
    string input = "babad";
    string result = longestPalindrome(input);
    cout << "Longest palindromic substring: " << result << endl;
    return 0;
}
