// 0/1 Knapsack problem 


#include <bits/stdc++.h>
using namespace std;

int knapSackHelper(int capacity, vector<int> &profit, vector<int> &weight, int n, vector<vector<int>> &dp)
{

    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    if (dp[n][capacity] != -1)
    {
        return dp[n][capacity];
    }

    if (weight[n - 1] > capacity)
    {
        dp[n][capacity] = knapSackHelper(capacity, profit, weight, n - 1, dp);
    }
    else
    {

        int include = profit[n - 1] + knapSackHelper(capacity - weight[n - 1], profit, weight, n - 1, dp);

        int exclude = knapSackHelper(capacity, profit, weight, n - 1, dp);

        dp[n][capacity] = max(include, exclude);
    }

    return dp[n][capacity];
}

int knapSack(int capacity, vector<int> &profit, vector<int> &weight, int n)
{

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    return knapSackHelper(capacity, profit, weight, n, dp);
}

int main()
{
    int bagCapacity = 4;
    vector<int> profit = {1, 2, 3};
    vector<int> weight = {4, 5, 1};

    int n = profit.size();

    cout << "Maximum value thief can generate: " << knapSack(bagCapacity, profit, weight, n) << endl;

    return 0;
}

