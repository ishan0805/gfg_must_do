class Solution
{
public:
    bool isPossible(int n, vector<pair<int, int> > &prerequisites)
    {

        int p = prerequisites.size();
        int count = 0;
        unordered_map<int, int> in_degree;
        vector<vector<int> > graph(n);
        vector<int> visited(n, 0);
        queue<int> q;
        for (auto task : prerequisites)
        {
            in_degree[task.first]++;
            graph[task.second].push_back(task.first);
        }
        for (int i = 0; i < n; i++)
        {
            if (in_degree[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
            }
        }
        while (!q.empty())
        {
            int curr_task = q.front();
            q.pop();
            count++;
            for (auto next_task : graph[curr_task])
            {
                if (visited[next_task] == 0)
                {

                    in_degree[next_task]--;
                    if (in_degree[next_task] == 0)
                    {
                        q.push(next_task);
                        visited[next_task] = 1;
                    }
                }
            }
        }
        return count == n;
    }
};