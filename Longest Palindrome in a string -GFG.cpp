//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        string result = "";
        int maxlen=0;
        for(int i=0; i<S.size(); i++)
        {
            int l=i, r=i;
            while(l>=0 && r<S.size() && S[l]==S[r])
            {
                if(r-l+1 > maxlen)
                {
                    maxlen=(r-l+1);
                    result = S.substr(l, r-l+1);
                }
                l--;
                r++;
            }
            l=i, r=i+1;
            while(l>=0 && r<S.size() && S[l]==S[r])
            {
                if(r-l+1 > maxlen)
                {
                    maxlen=(r-l+1);
                    result = S.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends