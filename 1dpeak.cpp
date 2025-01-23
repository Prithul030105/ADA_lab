#include <iostream>
using namespace std;

int peak(int arr[], int n)
{

    if (n == 1)
    {
        cout << "Peak is " << arr[0] << endl;
        return arr[0];
    }

    if (arr[0] > arr[1])
    {
        cout << "Peak is " << arr[0] << endl;
        return arr[0];
    }

    if (arr[n - 1] > arr[n - 2])
    {
        cout << "Peak is " << arr[n - 1] << endl;
        return arr[n - 1];
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            cout << "Peak is " << arr[i] << endl;
            return arr[i];
        }
    }

    return -1;
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

    peak(arr, n);

    return 0;
}
