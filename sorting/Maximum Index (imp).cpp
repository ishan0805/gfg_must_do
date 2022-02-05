class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.

    int maxIndexDiff(int a[], int n)
    {
        int leftMin[n];  // it is better to take less left
        int rightMax[n]; // it is better to take more to right
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                leftMin[i] = a[i];
                continue;
            }
            leftMin[i] = min(leftMin[i - 1], a[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                rightMax[i] = a[i];
                continue;
            }
            rightMax[i] = max(rightMax[i + 1], a[i]);
        }
        int i = 0, j = 0, diff = 0;
        // peerform merge function
        while (i < n && j < n)
        {

            if (leftMin[i] <= rightMax[j])
            {
                diff = max(diff, j - i);
                j++;
            }
            else
            {
                i++;
            }
        }
        return diff;
    }
};