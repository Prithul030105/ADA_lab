#include <iostream>
#define INF 9999
using namespace std;

int main()
{
    const int N = 8;
    int cost[N][N] = {0};

    cost[0][1] = 1;
    cost[0][2] = 2;
    cost[1][3] = 3;
    cost[1][4] = 4;
    cost[2][4] = 2;
    cost[2][5] = 3;
    cost[3][6] = 6;
    cost[4][6] = 1;
    cost[5][6] = 2;
    cost[6][7] = 1;

    int minCost[N];
    int path[N];

    minCost[N - 1] = 0;

    for (int i = N - 2; i >= 0; i--)
    {
        minCost[i] = INF;
        for (int j = i + 1; j < N; j++)
        {
            if (cost[i][j] != 0 && cost[i][j] + minCost[j] < minCost[i])
            {
                minCost[i] = cost[i][j] + minCost[j];
                path[i] = j;
            }
        }
    }

    cout << "Minimum cost from source to destination: " << minCost[0] << endl;

    cout << "Path: ";
    int i = 0;
    cout << i;
    while (i != N - 1)
    {
        i = path[i];
        cout << " -> " << i;
    }
    cout << endl;

    return 0;
}
