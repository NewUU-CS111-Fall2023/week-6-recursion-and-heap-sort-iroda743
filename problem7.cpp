#include <iostream>

int reverseDigits(int n, int reversed = 0) {
    if (n == 0) {
        return reversed;
    }

    return reverseDigits(n / 10, reversed * 10 + n % 10);
}

int main() {
    int n;

    std::cin >> n;

    int result = reverseDigits(n);

    std::cout << result << std::endl;

    return 0;
}
