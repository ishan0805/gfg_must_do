#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int findCuts(int n,vector<int>&dp ,int x, int y, int z)
    {
        if(n<0)
        {
            return INT_MIN;
        }
        if(dp[n]==-1)
        {
            int a=findCuts(n-x,dp,x,y,z);
            int b=findCuts(n-y,dp,x,y,z);
            int c=findCuts(n-z,dp,x,y,z);
            //a=((a==INT_MIN)?INT_MIN:a+1);
           // b=(b==INT_MIN?INT_MIN:b+1);
            //c=(c==INT_MIN?INT_MIN:c+1);
            dp[n]=max(a,b,c);
        }
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
       
      vector<int>dp(n+1,-1);
     int ans=findCuts(n,dp,x,y,z);
     return ans;
     //return (ans==INT_MIN?0:ans);
    
      
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends