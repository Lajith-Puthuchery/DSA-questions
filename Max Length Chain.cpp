//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};


// } Driver Code Ends
/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

class Solution{
public:
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        //Your code here
        vector<int> mlc(n,1);
        vector<pair<int,int>>pa;
        for(int i=0; i<n; i++)
        {
            pa.push_back(make_pair(p[i].first,p[i].second));
        }
        sort(pa.begin(), pa.end());
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(pa[i].first>pa[j].second && mlc[i]<=mlc[j])
                {
                    mlc[i]=mlc[j]+1;
                }
            }
        }
        int maxi=INT_MIN;
        for(int x: mlc)
        {
            if(x>maxi)
                maxi=x;
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends