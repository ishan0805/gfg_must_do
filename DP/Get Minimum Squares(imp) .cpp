class Solution
{
public:
    int MinSquares(int n)
    {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = INT_MAX;
            for (int p = 1; p <= 100; p++)
            {
                int sum = i - p * p;
                if (sum < 0)
                {
                    break;
                }
                dp[i] = min(dp[i], dp[sum] + 1);
                dp[i] %= 1000000007;
            }
        }
        return dp[n];
    }
};