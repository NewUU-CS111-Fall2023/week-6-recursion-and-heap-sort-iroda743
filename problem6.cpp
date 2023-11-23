#include <iostream>

void findSecondLargest(int &largest, int &secondLargest) {
    int num;

    std::cin >> num;

    if (num == 0) {
        return; 
    }

    if (num > largest) {
        secondLargest = largest;
        largest = num;
    } else if (num > secondLargest && num != largest) {
        secondLargest = num;
    }

    findSecondLargest(largest, secondLargest);
}

int main() {
    int largest = 0, secondLargest = 0;

    findSecondLargest(largest, secondLargest);

    std::cout << secondLargest << std::endl;

    return 0;
}
