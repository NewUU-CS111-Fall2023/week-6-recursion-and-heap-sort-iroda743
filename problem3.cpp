#include <iostream>

int sumOfDigits(int N) {
    if (N == 0) {
        return 0; 
    } else {
        return N % 10 + sumOfDigits(N / 10); 
    }
}

int main() {
    int N;

    std::cin >> N;

    int result = sumOfDigits(N);

    std::cout << result << std::endl;

    return 0;
}
