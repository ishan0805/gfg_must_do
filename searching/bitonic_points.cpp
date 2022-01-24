class Solution
{
public:
    int findMaximum(int arr[], int n)
    {
        int start = 0;
        int end = n - 1;
        // 1 2 3 4
        // 0 1 2 3
        // s=0,e=3,m=1 | s=1,e=3,m=2 | s=2,e=3, m=2
        if (n == 1)
        {
            return arr[0];
        }
        if (n == 2)
        {
            return max(arr[0], arr[1]);
        }

        while (start != end - 1)
        {
            int mid = start + (end - start) / 2;
            if (mid == n - 1)
            {
                return arr[mid];
            }
            if (mid != 0 && arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return arr[mid];
            }
            if (arr[mid] < arr[mid + 1])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        return max(arr[start], arr[end]);
    }
};