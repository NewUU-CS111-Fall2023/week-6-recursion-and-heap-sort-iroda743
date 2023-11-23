#include <iostream>
#include <string>
#include <cmath>

std::string add(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;

    int sizeA = a.size();
    int sizeB = b.size();
    int maxSize = std::max(sizeA, sizeB);

    for (int i = 0; i < maxSize || carry; ++i) {
        int digitA = i < sizeA ? a[sizeA - 1 - i] - '0' : 0;
        int digitB = i < sizeB ? b[sizeB - 1 - i] - '0' : 0;

        int sum = digitA + digitB + carry;
        carry = sum / 10;

        result.insert(result.begin(), '0' + (sum % 10));
    }

    return result;
}

std::string subtract(const std::string& a, const std::string& b) {
    std::string result;
    int borrow = 0;

    int sizeA = a.size();
    int sizeB = b.size();

    for (int i = 0; i < sizeA; ++i) {
        int digitA = a[sizeA - 1 - i] - '0';
        int digitB = i < sizeB ? b[sizeB - 1 - i] - '0' : 0;

        int diff = digitA - digitB - borrow;
        borrow = diff < 0 ? 1 : 0;

        result.insert(result.begin(), '0' + ((diff + 10) % 10));
    }

    return result;
}

std::string multiply(const std::string& a, const std::string& b) {
    int sizeA = a.size();
    int sizeB = b.size();

    if (sizeA == 0 || sizeB == 0) {
        return "0";
    }

    if (sizeA == 1 || sizeB == 1) {
        return std::to_string(std::stoi(a) * std::stoi(b));
    }

    int maxSize = std::max(sizeA, sizeB);
    int splitIndex = maxSize / 2;

    std::string aHigh = a.substr(0, sizeA - splitIndex);
    std::string aLow = a.substr(sizeA - splitIndex, splitIndex);
    std::string bHigh = b.substr(0, sizeB - splitIndex);
    std::string bLow = b.substr(sizeB - splitIndex, splitIndex);

    std::string z0 = multiply(aLow, bLow);
    std::string z1 = multiply(add(aLow, aHigh), add(bLow, bHigh));
    std::string z2 = multiply(aHigh, bHigh);

    std::string term1 = z2 + std::string(2 * splitIndex, '0');
    std::string term2 = subtract(subtract(z1, z2), z0) + std::string(splitIndex, '0');

    return add(add(term1, term2), z0);
}

int main() {
    std::string num1, num2;

    std::cin >> num1 >> num2;

    std::string result = multiply(num1, num2);

    std::cout << result << std::endl;

    return 0;
}
