#include <iostream>
#include <string>

bool isPalindrome(const std::string& word, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (word[start] != word[end]) {
        return false;
    }

    return isPalindrome(word, start + 1, end - 1);
}

int main() {
    std::string word;

    std::cin >> word;

    if (isPalindrome(word, 0, word.length() - 1)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
