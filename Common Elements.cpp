// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
        vector<int> common_element(vector<int>v1,vector<int>v2)
    {
        // Your code here
        vector<int> result;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(auto x: v1)
        {
            m1[x]++;
        }
        for(auto x: v2)
        {
            m2[x]++;
        }
        for(auto x: m1)
        {
            for(int i=0; i<min(x.second,m2[x.first]); i++)
            {
                result.push_back(x.first);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};

// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int>v1(n,0);
        for(int i=0;i<n;i++)
        {
            cin>>v1[i];
        }
        int m;
        cin>>m;
        vector<int>v2(m,0);
        for(int i=0;i<m;i++)
        {
            cin>>v2[i];
        }
        Solution ob;
        vector<int>result;
        result=ob.common_element(v1,v2);
        for(auto i:result)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        
    }
}  // } Driver Code Ends