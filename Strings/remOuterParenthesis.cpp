#include <iostream>
#include <string>
using namespace std;

string removeOuterParentheses(string s) {
    int open = 0;
    int close = 0;
    string ans = "";
    int start = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') open++;
        else if (s[i] == ')') close++;

        if (open == close) {
            ans += s.substr(start + 1, i - start - 1);
            start = i + 1;
        }
    }

    return ans;
}

int main() {
    string input;
    cout << "Enter a valid parentheses string: ";
    cin >> input;

    string result = removeOuterParentheses(input);
    cout << "Result after removing outer parentheses: " << result << endl;

    return 0;
}
