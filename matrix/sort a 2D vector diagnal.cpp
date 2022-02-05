class Solution
{
public:
    void diagonalSort(vector<vector<int>> &matrix, int n, int m)
    {

        vector<int> hold;
        // sort upper triangle

        for (int step = 1; step < m; step++)
        {
            int i = 0;
            int j = step;
            while (j < m && i < n)
            {
                hold.push_back(matrix[i++][j++]);
            }
            sort(hold.begin(), hold.end());
            j = step, i = 0;
            while (j < m && i < n)
            {
                matrix[i++][j++] = hold.back();
                hold.pop_back();
            }
        }
        // sort lower triangle
        for (int step = 1; step < n; step++)
        {
            int j = 0;
            int i = step;
            while (j < m && i < n)
            {
                hold.push_back(matrix[i++][j++]);
            }
            sort(hold.begin(), hold.end(), greater<int>());
            i = step, j = 0;
            while (j < m && i < n)
            {
                matrix[i++][j++] = hold.back();
                hold.pop_back();
            }
        }
    }
};