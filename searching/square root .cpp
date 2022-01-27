#define ll long long int
class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        ll start = 0;
        ll end = x;
        while (start != end - 1)
        {
            ll mid = start + (end - start) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            if (mid * mid < x)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        if (end * end == x)
            return end;

        return start;
    }
};