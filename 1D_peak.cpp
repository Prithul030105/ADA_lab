#include <iostream>
using namespace std;

int peak_element(int arr[], int low, int high, int n)
{

    int mid = (low + high) / 2;

    if (mid == 0)
    {
        cout << "peak element is " << arr[mid] << endl;
        return arr[mid];
    }
    if (arr[mid] >= arr[mid - 1])
    {
        cout << "peak element is " << arr[mid] << endl;
        return arr[mid];
    }
    if (mid == n - 1 || arr[mid] >= arr[mid + 1])
    {
        cout << "peak element is" << arr[mid] << endl;
        return arr[mid];
    }

    if (mid > 0 && (arr[mid - 1] > arr[mid]))
    {
        return peak_element(arr, low, mid - 1, n);
    }

    return peak_element(arr, mid + 1, high, n);
}

int peak(int arr[], int n)
{
    return peak_element(arr, 0, n - 1, n);
}

int main()
{
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    cout << "Now enter the elements in the array:" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int peakElement = peak(arr, n);

    return 0;
}
