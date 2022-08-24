//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    unordered_map<char,int> m;
    int start=0;
    int maxi=1;
    for(int i=0; i<s.size(); i++)
    {
        m[s[i]]++;
        while(m[s[i]]>1)
        {
            m[s[start]]--;
            start++;
        }
        if(i-start+1>maxi)
            maxi=i-start+1;
    }
    return maxi;
}