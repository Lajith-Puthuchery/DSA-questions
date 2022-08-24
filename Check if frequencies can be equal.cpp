// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    unordered_map<char,int> m;
	    for(auto c: s)
	    {
	        m[c]++;
	    }
        set<int>st;
        for(auto x: m)
        {
            st.insert(x.second);
        }
        if(st.size()==1)
        return true;
        if(st.size()!=2)
            return false;
        int min=INT_MAX;
        for(auto x: m)
        {
            if(x.second<min)
            min=x.second;
        }
        int min_count=0;
        for(auto x: m)
        {
            if(x.second==min)
            min_count++;
        }
         if(*(st.rbegin())-*(st.begin())==1 || (min==1 && min_count==1))
         return true;
         return false;
	}
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}


  // } Driver Code Ends