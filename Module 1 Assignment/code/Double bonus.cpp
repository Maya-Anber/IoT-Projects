#include <iostream>
#include <vector>
#include <algorithm>

// Function to check if the vector is sorted
bool isSorted(const std::vector<int>& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

// Function to perform a single pass of bubble sort
std::vector<int> bubbleSortPass(const std::vector<int>& vec) {
    std::vector<int> result(vec);
    for (size_t i = 0; i < result.size() - 1; ++i) {
        if (result[i] > result[i + 1]) {
            std::swap(result[i], result[i + 1]);
        }
    }
    return result;
}

// Recursive bubble sort function
std::vector<int> bubbleSort(const std::vector<int>& vec) {
    if (isSorted(vec)) {
        return vec;
    } else {
        return bubbleSort(bubbleSortPass(vec));
    }
}

int main() {
    std::vector<int> vec = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original array: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::vector<int> sortedVec = bubbleSort(vec);

    std::cout << "Sorted array: ";
    for (int num : sortedVec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
