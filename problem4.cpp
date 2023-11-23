#include <iostream>

bool isPrime(int n, int i = 2) {
    if (n <= 1) {
        return false; 
    }
    if (i * i > n) {
        return true;
    }
    if (n % i == 0) {
        return false;
    }
    return isPrime(n, i + 1); 
}

int main() {
    int n;

    std::cin >> n;

    if (isPrime(n)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
