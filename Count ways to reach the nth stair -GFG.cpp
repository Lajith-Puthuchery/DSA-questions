//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int climb(int n, vector<int>& dp)
    {
        int mod=1e9+7;
        if(n==1 || n==2)
            return n;
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=(climb(n-1, dp)%mod+climb(n-2, dp)%mod)%mod;
        return dp[n];
    }
    
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1, -1);
        return climb(n, dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends