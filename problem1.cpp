#include <iostream>

void printNumbers(int A, int B) {
    if (A < B) {
        std::cout << A << " ";
        printNumbers(A + 1, B);
    } else if (A > B) {
        std::cout << A << " ";
        printNumbers(A - 1, B);
    } else {
        std::cout << A << std::endl;
    }
}

int main() {
    int A, B;

   
    std::cin >> A;
    std::cin >> B;

    
    printNumbers(A, B);

    return 0;
}
