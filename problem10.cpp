#include <iostream>
#include <vector>
#include <algorithm>

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

std::string permuteString(const std::string& s) {
    std::vector<char> vowels;
    std::string result = s;

    // Collect vowels and their indices
    for (int i = 0; i < s.length(); ++i) {
        if (isVowel(s[i])) {
            vowels.push_back(s[i]);
        }
    }

    std::sort(vowels.begin(), vowels.end());

    int vowelIndex = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (isVowel(result[i])) {
            result[i] = vowels[vowelIndex++];
        }
    }

    return result;
}

int main() {
    std::string s;

    std::cin >> s;

    std::string result = permuteString(s);

    std::cout << result << std::endl;

    return 0;
}
