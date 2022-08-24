// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1)
            return 0;
        if(n==0 || arr[0]==0)
            return -1;
        vector<int> jump(n,INT_MAX);
        jump[0]=0;
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(i<=j+arr[j] && jump[j]!=-1)
                    jump[i]=min(jump[i],jump[j]+1);
            }
        }
        return jump[n-1]==INT_MAX ? -1 : jump[n-1];
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends