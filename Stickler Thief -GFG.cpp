//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n, 0);
        dp[0]=arr[0];
        dp[1]=arr[1];
        int max=0;
        for(int i=2; i<n; i++)
        {
            dp[i]=dp[max]+arr[i];
            if(dp[i-1]>dp[max])
                max=i-1;
        }
        int res=INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(dp[i]>res)
                res=dp[i];
        }
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends