#include <iostream>
using namespace std;

int n = 4;
int dist[4][4] = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}};

int dp[16][4];

const int MAX_VAL = 1000000;

int tsp(int mask, int pos)
{
    if (mask == (1 << n) - 1)
        return dist[pos][0];

    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = MAX_VAL;

    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newCost = dist[pos][city] + tsp(mask | (1 << city), city);
            if (newCost < ans)
                ans = newCost;
        }
    }

    dp[mask][pos] = ans;
    return ans;
}

int main()
{

    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    int minCost = tsp(1, 0);
    cout << "Minimum travel cost: " << minCost << endl;

    return 0;
}
