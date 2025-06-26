#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; i--) {
        if ((num[i] - '0') & 1) {
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    string input;
    cout << "Enter a numeric string: ";
    cin >> input;

    string result = largestOddNumber(input);
    if (!result.empty()) {
        cout << "Largest odd number: " << result << endl;
    } else {
        cout << "No odd number found." << endl;
    }

    return 0;
}
