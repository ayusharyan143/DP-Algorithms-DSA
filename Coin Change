// Coin Change

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of coins needed
int minCoins(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
    {
        for (int coin : coins)
        {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

// Function to find the number of ways to make change
int countWays(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins)
    {
        for (int i = coin; i <= amount; ++i)
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 3};
    int amount = 5;

    int min_coins = minCoins(coins, amount);
    int ways = countWays(coins, amount);

    cout << "Minimum coins needed: " << min_coins << endl;
    cout << "Number of ways to make change: " << ways << endl;

    return 0;
}
