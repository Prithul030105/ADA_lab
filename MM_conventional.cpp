#include <iostream>

using namespace std;

void addMatrix(int A[2][2], int B[2][2], int result[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

void multiplyDivideConquer(int A[2][2], int B[2][2], int C[2][2])
{
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];

    M1[0][0] = A[0][0] * B[0][0];
    M1[0][1] = A[0][0] * B[0][1];
    M1[1][0] = A[1][0] * B[0][0];
    M1[1][1] = A[1][0] * B[0][1];

    M2[0][0] = A[0][1] * B[1][0];
    M2[0][1] = A[0][1] * B[1][1];
    M2[1][0] = A[1][1] * B[1][0];
    M2[1][1] = A[1][1] * B[1][1];

    addMatrix(M1, M2, C);
}

void printMatrix(int matrix[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2] = {{0, 0}, {0, 0}};

    multiplyDivideConquer(A, B, C);

    cout << "Result of Matrix Multiplication using Divide and Conquer:\n";
    printMatrix(C);

    return 0;
}
