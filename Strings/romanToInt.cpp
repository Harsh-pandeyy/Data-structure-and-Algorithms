#include <iostream>
#include <string>
using namespace std;

int getval(char ch) {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];
        if (i + 1 < s.size() && getval(ch) < getval(s[i + 1])) {
            sum -= getval(ch);
        } else {
            sum += getval(ch);
        }
    }
    return sum;
}

int main() {
    string roman;
    cin >> roman;
    int result = romanToInt(roman);
    cout << result << endl;
    return 0;
}
