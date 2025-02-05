#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n = 1000;
    vector<int> arr(n);
    
    srand(time(0));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    auto start = high_resolution_clock::now();
    insertionSort(arr);
    auto stop = high_resolution_clock::now();
    
    double duration = duration_cast<milliseconds>(stop - start).count();
    cout << "Insertion Sort Time: " << duration << " ms\n";

    return 0;
}
