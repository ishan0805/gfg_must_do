class Solution
{
public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> a, int n, vector<int> b, int m)
    {
        map<int, int> check;
        for (int i = 0; i < n; i++)
        {
            check[a[i]]++;
        }
        int curr = 0;
        for (int i = 0; i < m; i++)
        {
            if (check.find(b[i]) != check.end())
            {
                while (check[b[i]])
                {
                    a[curr++] = b[i];
                    check[b[i]]--;
                }
                check.erase(b[i]);
            }
        }
        for (auto p : check)
        {
            int element = p.first;
            while (check[element])
            {
                a[curr++] = element;
                check[element]--;
            }
        }
        return a;
    }
};