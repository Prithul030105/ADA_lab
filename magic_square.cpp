#include <iostream>
using namespace std;

void generateMagicSquare(int n)
{
    int magicSquare[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            magicSquare[i][j] = 0;
        }
    }

    int i = 0, j = n / 2;

    for (int num = 1; num <= n * n; num++)
    {
        magicSquare[i][j] = num; // Place the number

        int newi = i - 1; // Move up
        int newj = j + 1; // Move right

        if (newi < 0)
            newi = n - 1; // Wrap to the last row
        if (newj == n)
            newj = 0; // Wrap to the first column

        if (magicSquare[newi][newj] != 0)
        {
            i = i + 1; // Move down
        }
        else
        {
            i = newi;
            j = newj;
        }
    }

    cout << "Magic Square of size " << n << ":\n";
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            cout << magicSquare[r][c] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter an odd number for the magic square: ";
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "Only odd numbers are allowed!" << endl;
    }
    else
    {
        generateMagicSquare(n);
    }

    return 0;
}
