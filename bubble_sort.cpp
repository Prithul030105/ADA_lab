#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n = 1000; // Change this for larger input
    vector<int> arr(n);
    
    // Generate random numbers
    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    auto start = high_resolution_clock::now();
    bubbleSort(arr);
    auto stop = high_resolution_clock::now();
    
    double duration = duration_cast<milliseconds>(stop - start).count();
    cout << "Bubble Sort Time: " << duration << " ms\n";

    return 0;
}
