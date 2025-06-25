#include <iostream>
#include <string>
using namespace std;

string reverseWords(string s) {
    string ans = "";
    int i = 0;

    while (i < s.size()) {
        // Skip leading spaces
        while (i < s.size() && s[i] == ' ') i++;

        // Extract a word
        string temp = "";
        while (i < s.size() && s[i] != ' ') {
            temp += s[i];
            i++;
        }

        // Add the word to the front of ans
        if (!temp.empty()) {
            if (ans.empty())
                ans = temp;
            else
                ans = temp + ' ' + ans;
        }
    }

    return ans;
}

int main() {
    string input;
    cout << "Enter a sentence: ";
    getline(cin, input);  // Allows multi-word input with spaces

    string result = reverseWords(input);
    cout << "Reversed words: " << result << endl;

    return 0;
}
