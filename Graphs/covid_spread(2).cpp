class Solution
{
public:
    bool save(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int helpaterp(vector<vector<int> > hospital)
    {
        int n = hospital.size();
        int m = hospital[0].size();
        vector<vector<int> > visited(n, vector<int>(m, 0));
        queue<pair<int, int> > q;
        int dir[8] = {0, 1, 1, 0, -1, 0, 0, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (hospital[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            visited[i][j] = 1;
            for (int step = 0; step < 8; step += 2)
            {
                int i_next = i + dir[step];
                int j_next = j + dir[step + 1];
                if (save(i_next, j_next, n, m) && visited[i_next][j_next] == 0 && hospital[i_next][j_next] == 1)
                {
                    hospital[i_next][j_next] = hospital[i][j] + 1;
                    visited[i_next][j_next] = 1;
                    q.push({i_next, j_next});
                }
            }
        }
        int maxTime = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (hospital[i][j] == 1)
                {
                    return -1;
                }
                maxTime = max(maxTime, hospital[i][j] - 2);
            }
        }
        return maxTime;
    }
};
