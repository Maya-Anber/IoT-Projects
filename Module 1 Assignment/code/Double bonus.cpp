#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to check if the vector is sorted
bool isSorted(const vector<int>& vec) {
    return is_sorted(vec.begin(), vec.end());
}

// Function to perform a single pass of bubble sort
vector<int> bubbleSortPass(const vector<int>& vec) {
    vector<int> result(vec);
    for (size_t i = 0; i < result.size() - 1; ++i) {
        if (result[i] > result[i + 1]) {
            swap(result[i], result[i + 1]);
        }
    }
    return result;
}

// Recursive bubble sort function
vector<int> bubbleSort(const vector<int>& vec) {
    if (isSorted(vec)) {
        return vec;
    } else {
        return bubbleSort(bubbleSortPass(vec));
    }
}

int main() {
    vector<int> vec = {64, 34, 25, 12, 22, 11, 90};

    cout << "Original array: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> sortedVec = bubbleSort(vec);

    cout << "Sorted array: ";
    for (int num : sortedVec) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
