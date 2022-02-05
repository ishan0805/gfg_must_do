class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    static

        int
        findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);
        int i = 1, j = 0;
        int curr_taken = 1;
        int max_taken = 1;
        // j-> points to the least time of train that hasnt left
        // i-> points to the arriving train
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                curr_taken++;
            }
            else
            {
                /*  if(curr_taken>1)
                  curr_taken--;*/

                j++;
            }
            i++;
            max_taken = max(max_taken, curr_taken);
        }
        return max_taken;
    }
};
