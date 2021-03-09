#include <iostream>

bool isPermutationOfPalindrome(std::string s) {
    int chars[26] = {};

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if ('a' <= c && c <= 'z') {
            chars[c - 'a']++;
        } else if ('A' <= c && c <= 'Z') {
            chars[c - 'A']++;
        } else {
            continue;
        }
    }

    int n_odd = 0;

    for (int i = 0; i < 26; i++) {
        int n = chars[i];
        if ((n & 0x1) == 0x1) {
            n_odd++;
        }
    }

    return n_odd <= 1;
}

int main() {
    std::string s1 = "Tact Coa";
    std::string s2 = "Tact CoaO";
    std::string s3 = "Tact Coay";

    std::cout << isPermutationOfPalindrome(s1) << std::endl;
    std::cout << isPermutationOfPalindrome(s2) << std::endl;
    std::cout << isPermutationOfPalindrome(s3) << std::endl;
}
