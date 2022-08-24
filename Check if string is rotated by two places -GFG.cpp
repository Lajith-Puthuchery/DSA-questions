//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        string anti1(str1.size(),' '), clock1(str1.size(),' ');
        string temp;
        int n=str1.size();
        for(int i=0; i<2; i++)
        {
            anti1[n-2+i]=str1[i];
        }
        for(int i=2; i<n; i++)
        {
            anti1[i-2]=str1[i];
        }
        
        for(int i=n-2; i<n; i++)
        {
            clock1[i-n+2]=str1[i];
        }
        for(int i=0; i<n-2; i++)
        {
            clock1[i+2]=str1[i];
        }
        
        if(clock1==str2 || anti1==str2)
            return true;
        else
            return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends