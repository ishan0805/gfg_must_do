class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int have_row = 0;
        int have_col = 0;
        int check_row[n] = {0};
        int check_col[m] = {0};
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 1)
            {
                have_row = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {

            if (matrix[i][0] == 1)
            {
                have_col = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == 1)
                {
                    check_row[i] = 1;
                    check_col[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && have_row)
                {
                    matrix[i][j] = 1;
                }
                else if (j == 0 && have_col)
                {
                    matrix[i][j] = 1;
                }
                else if (check_row[i] || check_col[j])
                {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};