#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()

{
    srand(time(0));

    int n = 10;
    int m = 50;

    for (int i = 0; i < 9; i++)
    {
        auto start = high_resolution_clock::now();

        int *arr = new int[n];

        for (int j = 0; j < n; j++)
        {
            arr[j] = rand() % m;
        }

        quickSort(arr, 0, n - 1);

        auto end = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(end - start);

        cout << "Size = " << n << "   Time = " << duration.count() << " ns" << endl;

        delete[] arr;
        n *= 10;
        m *= 10;
    }

    return 0;
}
