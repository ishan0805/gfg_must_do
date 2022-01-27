class Solution
{

public:
    vector<long long> findMissing(long long a[], long long b[],
                                  int n, int m)
    {
        unordered_set<long long> st;
        for (int i = 0; i < m; i++)
        {
            st.insert(b[i]);
        }
        vector<long long> ans;
        for (int i = 0; i < n; i++)
        {
            if (st.find(a[i]) == st.end())
            {
                ans.push_back(a[i]);
            }
        }
        return ans;
    }
};
