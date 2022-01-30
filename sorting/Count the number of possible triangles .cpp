class Solution
{
public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr + n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                int sum = arr[i] + arr[j];
                auto pos = lower_bound(arr, arr + n, sum) - arr;

                ans += (pos - j) - 1;
            }
        }
        return ans;
    }
};
