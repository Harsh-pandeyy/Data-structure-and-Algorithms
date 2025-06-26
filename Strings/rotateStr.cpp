#include <iostream>
#include <queue>
#include <string>

bool rotateString(std::string s, std::string goal) {
    if (s.size() != goal.size()) {
        return false;
    }

    std::queue<char> q1, q2;
    for (int i = 0; i < s.length(); i++) {
        q1.push(s[i]);
    }
    for (int i = 0; i < goal.length(); i++) {
        q2.push(goal[i]);
    }

    if (q1 == q2) return true;

    int k = goal.size() - 1;
    while (k != 0) {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q1 == q2) return true;
        k--;
    }

    return false;
}

int main() {
    std::string s = "abcde";
    std::string goal = "cdeab";

    if (rotateString(s, goal)) {
        std::cout << goal << " is a rotation of " << s << std::endl;
    } else {
        std::cout << goal << " is not a rotation of " << s << std::endl;
    }

    return 0;
}
