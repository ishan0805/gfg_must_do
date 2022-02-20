class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        int curr_max = 0;
        map<int, int> freq;
        for (int i = 0; i < k; i++)
        {
            curr_max = max(curr_max, arr[i]);
            freq[arr[i]]++;
        }
        vector<int> ans;
        ans.push_back(curr_max);
        for (int i = k; i < n; i++)
        {
            int pre_pos = i - k;
            freq[arr[pre_pos]]--;
            if (freq[arr[pre_pos]] == 0)
            {
                freq.erase(arr[pre_pos]);
            }
            freq[arr[i]]++;
            ans.push_back((*(--freq.end())).first);
        }
        return ans;
    }
};