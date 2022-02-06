class Solution
{
    // starts form the end because on left elements are lesser , below elements are graeter
    // this gives a true false situatuon to search for the element
public:
    // Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x)
    {
        int i = n - 1, j = m - 1;
        while (i < n && j >= 0)
        {
            if (x < matrix[i][j])
            {
                j--;
            }
            else if (x > matrix[i][j])
            {
                i++;
            }
            else if (x == matrix[i][j])
            {
                return 1;
            }
        }
        return 0;
    }
};