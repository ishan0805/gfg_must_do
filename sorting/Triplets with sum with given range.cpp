// In two pointer if less start from begin , if more start from end
class Solution
{

public:
    int countTriplets(int arr[], int n, int l, int r)
    {
        sort(arr, arr + n);
        int ans = (n * (n - 1) * (n - 2)) / 6;
        int less = 0, more = 0;
        // For finding triplet less than l
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = arr[j] + arr[k] + arr[i];
                if (sum >= l)
                {
                    k--;
                }
                else
                {
                    less += (k - j);
                    j++;
                }
            }
        }
        // For finding triplet more than r
        for (int i = n - 1; i > 1; i--)
        {
            int j = i - 1;
            int k = 0;
            while (j > k)
            {
                int sum = arr[j] + arr[k] + arr[i];
                if (sum <= r)
                {
                    k++;
                }
                else
                {
                    more += (j - k);
                    j--;
                }
            }
        }
        return ans - (less + more);
    }
};