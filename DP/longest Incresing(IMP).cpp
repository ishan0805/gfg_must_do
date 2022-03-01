class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> v;
        if (n == 0)
        {
            return 0;
        }
        int ans = 1;
        v.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            auto it = upper_bound(v.begin(), v.end(), a[i]);
            if (it == v.end())
            {
                if (v.back() != a[i]) // condition for duplicate
                {
                    v.push_back(a[i]);
                    ans++;
                }
            }
            else
            {
                v[it - v.begin()] = a[i];
            }
        }
        return ans;
    }
};
