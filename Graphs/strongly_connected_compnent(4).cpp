
class Solution
{
public:
    // find order of last visited vertices in a stack
    void findOrder(vector<int> &visited, vector<int> adj[], stack<int> &s, int root)
    {
        visited[root] = 1;
        for (auto u : adj[root])
        {
            if (visited[u] == 0)
            {
                findOrder(visited, adj, s, u);
            }
        }
        s.push(root);
    }
    void dfs(vector<int> &visited, vector<vector<int> > &transportGraph, int root)
    {
        visited[root] = 1;
        for (auto u : transportGraph[root])
        {
            if (visited[u] == 0)
            {
                dfs(visited, transportGraph, u);
            }
        }
    }

    vector<vector<int> > transportOfGraph(vector<int> adj[], int n)
    {
        vector<vector<int> > transportGraph(n);
        for (int i = 0; i < n; i++)
        {
            for (int u : adj[i])
            {
                transportGraph[u].push_back(i);
            }
        }
        return transportGraph;
    }
    //Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
        stack<int> s;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                findOrder(visited, adj, s, i);
            }
        }
        vector<vector<int> > transportGraph = transportOfGraph(adj, n);
        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
        }
        int numberOfConnections = 0;
        while (!s.empty())
        {
            int root = s.top();
            s.pop();
            if (visited[root] == 0)
            {
                numberOfConnections++;
                dfs(visited, transportGraph, root);
            }
        }
        return numberOfConnections;
    }
};
