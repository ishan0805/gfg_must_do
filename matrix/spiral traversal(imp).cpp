// change 4 parameter i->n j->m, j->0 (st_j) i->0(st_i)
class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int n, int m)
    {
        int c = 0;
        int st_n = 1;
        int st_m = 0;
        vector<int> ans;
        int i = 0, j = 0;
        int total_element = n * m;

        while (c != total_element)
        {

            while (j < m)
            {
                ans.push_back(matrix[i][j++]);
                c++;
            }
            j--;
            i++;
            m--;

            while (i < n && c != total_element)
            {
                ans.push_back(matrix[i++][j]);
                c++;
            }

            n--;
            i--;
            j--;

            while (j >= st_m && c != total_element)
            {
                ans.push_back(matrix[i][j--]);
                c++;
            }
            j++;
            i--;
            st_m++;

            while (i >= st_n && c != total_element)
            {
                ans.push_back(matrix[i--][j]);
                c++;
            }
            i++;
            j++;
            st_n++;
        }
        return ans;
    }
};