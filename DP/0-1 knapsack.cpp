class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int findMaxValue(int i, int capacity, int wt[], int val[], vector<vector<int>> &dp)
    {
        if (capacity < 0)
        {
            return INT_MIN;
        }
        if (i < 0)
        {
            return 0;
        }
        if (dp[i][capacity] == -1)
        {
            dp[i][capacity] = max(findMaxValue(i - 1, capacity - wt[i], wt, val, dp) + val[i], findMaxValue(i - 1, capacity, wt, val, dp));
        }
        return dp[i][capacity];
    }
    int knapSack(int capacity, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return findMaxValue(n - 1, capacity, wt, val, dp);
    }
};