//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int n=str.size();
		    int mod=1e9+7;
		    int count[n+1];
		    count[0]=1;
		    count[1]=1;
		    if(str[0]=='0')
		        return 0;
		    for(int i=2; i<=n; i++)
		    {
		        int x1=0, x2=0;
		        count[i]=0;
		        if(str[i-1]>'0')
		            x1=count[i-1];
		        if(str[i-2]=='1' || (str[i-2]=='2' && str[i-1]<'7'))
		            x2=count[i-2];
		        count[i]=(x1+x2)%mod;
		    }
		    return count[n];
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends