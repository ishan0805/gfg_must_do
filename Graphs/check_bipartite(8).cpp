// Perform bfs and give colors , check the neighbours if two having same color its not
// bipartite

class Solution
{
public:
    bool isBipartite(int n, vector<int> adj[])
    {
        vector<int> colors(n, -1);
        vector<int> visited(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                q.push(i);
                int color = 1;
                colors[i] = color;
                while (!q.empty())
                {
                    int src = q.front();
                    q.pop();
                    color = colors[src];
                    for (auto u : adj[src])
                    {
                        if (!visited[u])
                        {
                            visited[u] = 1;
                            colors[u] = color ^ 1;
                            q.push(u);
                        }
                        else if (colors[u] == color)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};