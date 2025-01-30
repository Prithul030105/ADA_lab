#include <iostream>
using namespace std;
int findpeak(int **arr, int rows, int cols)
{
    int startRow = 0, endRow = rows - 1;
    int startCol = 0, endCol = cols - 1;

    while (true)
    {

        int midRow = (startRow + endRow) / 2;
        int midCol = (startCol + endCol) / 2;

        if (checkTop(arr, midRow, midCol) &&
            checkBottom(arr, midRow, midCol, rows) &&
            checkLeft(arr, midRow, midCol) &&
            checkRight(arr, midRow, midCol, cols))
        {
            cout << "The peak element is " << arr[midRow][midCol]
                 << " at (" << midRow << ", " << midCol << ")" << endl;
            return arr[midRow][midCol];
        }

        if (midRow > 0 && arr[midRow - 1][midCol] > arr[midRow][midCol])
        {

            endRow = midRow - 1;
        }
        else if (midRow < rows - 1 && arr[midRow + 1][midCol] > arr[midRow][midCol])
        {

            startRow = midRow + 1;
        }
        else if (midCol > 0 && arr[midRow][midCol - 1] > arr[midRow][midCol])
        {

            endCol = midCol - 1;
        }
        else if (midCol < cols - 1 && arr[midRow][midCol + 1] > arr[midRow][midCol])
        {

            startCol = midCol + 1;
        }
    }
}

int checkTop(int **arr, int midRow, int midCol)
{
    if (midRow == 0 || arr[midRow - 1][midCol] <= arr[midRow][midCol])
    {
        return 1;
    }
    return 0;
}

int checkBottom(int **arr, int midRow, int midCol, int rows)
{
    if (midRow == rows - 1 || arr[midRow + 1][midCol] <= arr[midRow][midCol])
    {
        return 1;
    }
    return 0;
}

int checkLeft(int **arr, int midRow, int midCol)
{
    if (midCol == 0 || arr[midRow][midCol - 1] <= arr[midRow][midCol])
    {
        return 1;
    }
    return 0;
}

int checkRight(int **arr, int midRow, int midCol, int cols)
{
    if (midCol == cols - 1 || arr[midRow][midCol + 1] <= arr[midRow][midCol])
    {
        return 1;
    }
    return 0;
}

int main()
{
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Dynamically allocate a 2D array
    int **arr = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new int[cols];
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            cin >> arr[i][j];
        }
    }

    findpeak(arr, rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
