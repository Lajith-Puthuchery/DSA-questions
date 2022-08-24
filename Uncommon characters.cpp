//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            map<char,int>mA;
            map<char,int>mB;
            string result="";
            for(auto c: A)
            {
                mA[c]++;
            }
            for(auto c: B)
            {
                mB[c]++;
            }
            for(char c='a'; c<='z'; c++)
            {
                if((!mA[c] && mB[c]) || (mA[c] && !mB[c]))
                {
                    result+=c;
                }
            }
            return result=="" ? "-1" : result;
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends