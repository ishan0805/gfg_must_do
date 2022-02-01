
// use two pointer , start with n^3 to n^2
class Solution
{
public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr + n);
        int ans = 0;
        for (int i = n - 1; i > 1; i--)
        {
            int j = 0;
            int k = i - 1;
            while (k > j)
            {
                int sum = arr[j] + arr[k];
                if (sum > arr[i])
                {
                    ans += (k - j);
                    k--;
                }
                else
                {
                    j++;
                }
            }
        }
        return ans;
    }
};