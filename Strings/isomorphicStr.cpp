#include <iostream>
#include <unordered_map>
#include <string>

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, char> charMappingMap;
    std::unordered_map<char, char> reverseCharMappingMap;

    for (int i = 0; i < s.length(); i++) {
        char original = s[i];
        char replacement = t[i];

        if (charMappingMap.find(original) == charMappingMap.end()) {
            if (reverseCharMappingMap.find(replacement) != reverseCharMappingMap.end()) {
                return false;
            }
            charMappingMap[original] = replacement;
            reverseCharMappingMap[replacement] = original;
        } else {
            if (charMappingMap[original] != replacement) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::string s = "egg";
    std::string t = "add";

    if (isIsomorphic(s, t)) {
        std::cout << s << " and " << t << " are isomorphic." << std::endl;
    } else {
        std::cout << s << " and " << t << " are not isomorphic." << std::endl;
    }

    return 0;
}
