int Search(vector<int> vec, int k)
{
    int n = vec.size();
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        if (vec[0] == k)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    int end = vec.size() - 1;
    int begin = 0;
    // 1 2 3
    // 0 1 2
    // s=0,e=2,m=1,
    while (end > begin)
    {
        int mid = begin + (end - begin) / 2;
        if (vec[mid] == k)
        {
            return mid;
        }
        //check which part of array is sorted left or right

        if (vec[begin] < vec[mid])
        // left is sorted
        {
            if (k >= vec[begin] && k < vec[mid])
            // k is between begin and mid
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }
        else // right is sorted
        {
            if (k > vec[mid] && k <= vec[end])
            // k is between end and mid
            {
                begin = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
    if (vec[begin] == k)
    {
        return begin;
    }
    if (vec[end] == k)
    {
        return end;
    }
    return -1;
}