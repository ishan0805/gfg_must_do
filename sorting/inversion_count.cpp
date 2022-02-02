class Solution
{
#define ll long long
public:
    void mergeSort(long long arr[], ll left, ll right, ll &ans)
    {
        if (left < right)
        {
            ll mid = left + (right - left) / 2;
            mergeSort(arr, left, mid, ans);
            mergeSort(arr, mid + 1, right, ans);
            countInversion(arr, left, mid, right, ans);
        }
    }
    void countInversion(long long arr[], ll left, ll mid, ll right, ll &ans)
    {
        ll left_arr[mid - left + 1];
        ll right_arr[right - mid];
        int i = 0, len_left = mid - left + 1;
        int j = 0, len_right = right - mid;
        int curr = left;

        for (int it = left; it <= mid; it++)
        {
            left_arr[i++] = arr[it];
        }
        for (int it = mid + 1; it <= right; it++)
        {
            right_arr[j++] = arr[it];
        }
        i = 0, j = 0;

        while (i < len_left && j < len_right)
        {
            if (left_arr[i] > right_arr[j])
            {
                ans += (len_left - i);
                arr[curr++] = right_arr[j++];
            }
            else
            {
                arr[curr++] = left_arr[i++];
            }
        }
        while (i < len_left)
        {
            arr[curr++] = left_arr[i++];
        }
        while (j < len_right)
        {
            arr[curr++] = right_arr[j++];
        }
    }
    long long int inversionCount(long long arr[], long long n)
    {
        ll ans = 0;
        mergeSort(arr, 0, n - 1, ans);
        return ans;
    }
};