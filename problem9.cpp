#include <iostream>
#include <vector>

class Heap {
private:
    std::vector<int> heap;

    void maxHeapify(int i, int size) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] > heap[largest]) {
            largest = left;
        }

        if (right < size && heap[right] > heap[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            maxHeapify(largest, size);
        }
    }

public:
    Heap(const std::vector<int>& array) : heap(array) {}

    void buildMaxHeap() {
        int size = heap.size();

        for (int i = size / 2 - 1; i >= 0; --i) {
            maxHeapify(i, size);
        }
    }

    void heapSort() {
        int size = heap.size();

        buildMaxHeap();

        for (int i = size - 1; i > 0; --i) {
            std::swap(heap[0], heap[i]);
            maxHeapify(0, i);
        }
    }

    void printHeap() const {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    // Example usage
    std::vector<int> arr1 = {4, 10, 3, 5, 1};
    Heap heap1(arr1);
    heap1.heapSort();
    std::cout << "Sorted Heap 1: ";
    heap1.printHeap();

    std::vector<int> arr2 = {25, 17, 36, 2, 8, 19, 1};
    Heap heap2(arr2);
    heap2.heapSort();
    std::cout << "Sorted Heap 2: ";
    heap2.printHeap();

    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    Heap heap3(arr3);
    heap3.heapSort();
    std::cout << "Sorted Heap 3: ";
    heap3.printHeap();

    return 0;
}
