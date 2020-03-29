#include <iostream>
#include <string>

bool isDuplication(std::string s) {
    int memo[26];
    for (int i = 0; i < 26; i++) 
        memo[i] = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        memo[c - 'a']++;
        if (memo[c - 'a'] >= 2) 
            return true;
    }

    return false;
}

bool isDuplicateWithNoDataStructure(std::string s) {
    for (char c = 'a'; c <= 'z'; c++) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (c == s[i]) {
                count++;
            }
            if (count >= 2) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::cout << isDuplicateWithNoDataStructure("hello") << std::endl;
    std::cout << isDuplicateWithNoDataStructure("hlio") << std::endl;
}
