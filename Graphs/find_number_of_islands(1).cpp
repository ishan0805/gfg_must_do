// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int dir[16] ={0,1,1,0,-1,0,0,-1,-1,1,1,1,1,-1,-1,-1};
    bool save(int i,int j,int n,int m)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    
    
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&visited,int i ,int j,int n,int m)
    {
        visited[i][j]=1;
        for(int step=0;step<16;step+=2)
        {
            int next_i = i+dir[step];
            int next_j = j+dir[step+1];
            if(save(next_i,next_j,n,m)&&visited[next_i][next_j]==0&&grid[next_i][next_j]=='1')
           {
                dfs(grid,visited,next_i,next_j,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int numberOfIslands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                    dfs(grid,visited,i,j,n,m);
                    numberOfIslands++;
                }
            }
        }
        return numberOfIslands;
    }
};