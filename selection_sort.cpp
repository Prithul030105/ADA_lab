#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int n = 1000;
    vector<int> arr(n);
    
    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    auto start = high_resolution_clock::now();
    selectionSort(arr);
    auto stop = high_resolution_clock::now();
    
    double duration = duration_cast<milliseconds>(stop - start).count();
    cout << "Selection Sort Time: " << duration << " ms\n";

    return 0;
}
