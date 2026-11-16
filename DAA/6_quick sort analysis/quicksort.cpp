#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high, bool randomized) {
    if (randomized) {
        int randomIndex = low + rand() % (high - low + 1);
        swap(arr[randomIndex], arr[high]);
    }

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high, bool randomized) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, randomized);
        quickSort(arr, low, pivotIndex - 1, randomized);
        quickSort(arr, pivotIndex + 1, high, randomized);
    }
}

double measure(vector<int>& arr, bool randomized) {
    clock_t start = clock();
    quickSort(arr, 0, static_cast<int>(arr.size()) - 1, randomized);
    return double(clock() - start) / CLOCKS_PER_SEC;
}

void printArray(const string& label, const vector<int>& arr) {
    cout << label;
    for (int value : arr) {
        cout << value << ' ';
    }
    cout << '\n';
}

int main() {
    int n;
    cout << "Enter the number of elements for the array: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Please enter a non-negative integer.\n";
        return 1;
    }

    srand(static_cast<unsigned>(time(nullptr)));
    vector<int> original(n);
    for (int& value : original) {
        value = rand() % 100000 + 1;
    }

    vector<int> deterministic = original;
    vector<int> randomized = original;
    double deterministicTime = measure(deterministic, false);
    double randomizedTime = measure(randomized, true);

    printArray("\nOriginal array: ", original);
    printArray("\nDeterministic sorted array: ", deterministic);
    printArray("Randomized sorted array: ", randomized);

    cout << "Deterministic time: " << deterministicTime << "s\n";
    cout << "Randomized time: " << randomizedTime << "s\n";

    return 0;
}
