class Solution
{
public:
    //Function to find unit area of the largest region of 1s.
    bool save(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int dir[16] = {0, 1, 1, 0, -1, 0, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j])
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    int curr_area = 0;
                    while (!q.empty())
                    {
                        auto src = q.front();
                        q.pop();
                        curr_area++;
                        int curr_i = src.first;
                        int curr_j = src.second;
                        for (int step = 0; step < 16; step += 2)
                        {
                            int next_i = curr_i + dir[step];
                            int next_j = curr_j + dir[step + 1];
                            if (save(next_i, next_j, n, m) && !visited[next_i][next_j] && grid[next_i][next_j] == 1)
                            {
                                visited[next_i][next_j] = 1;
                                q.push({next_i, next_j});
                            }
                        }
                    }
                    maxArea = max(maxArea, curr_area);
                }
            }
        }
        return maxArea;
    }
};
