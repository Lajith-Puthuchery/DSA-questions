// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        vector<ll> prefix_sum;
        ll sum=0;
        for(auto x: arr)
        {
            sum+=x;
            prefix_sum.push_back(sum);
        }
        unordered_map<ll,int> m;
        for(auto x: prefix_sum)
        {
            m[x]++;
        }
        ll total=0;
        for(auto x: m)
        {
            if(x.first==0)
            {
                total+=(x.second)*(x.second+1)/2;
            }
            else if(x.second>1)
            {
                total+=(x.second)*(x.second-1)/2;
            }
        }
        return total;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}  // } Driver Code Ends