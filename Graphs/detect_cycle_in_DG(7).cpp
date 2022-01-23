class Solution
{
public:
    bool dfs(int src, vector<int> adj[], vector<int> &visited, vector<int> &temp)
    {
        visited[src] = 1;
        temp[src] = 1;
        bool result = false;
        for (auto u : adj[src])
        {
            if (visited[u] && temp[u])
            {
                result = true;
            }
            else if (!visited[u])
            {
                result |= dfs(u, adj, visited, temp);
            }
        }
        temp[src] = 0;
        return result;
    }
    bool isCyclic(int n, vector<int> adj[])
    {
        vector<int> visited(n, 0);
        vector<int> temp(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i], dfs(i, adj, visited, temp))
            {
                return true;
            }
        }
        return false;
    }
};