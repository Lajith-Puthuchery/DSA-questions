//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    static bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> as;
        pair<int,int> p;
        for(int i=0; i<n; i++)
        {
            p.first=start[i];
            p.second=end[i];
            as.push_back(p);
        }
        sort(as.begin(), as.end(), sortbysec);
        int count=1;
        int i=1, j=0;
        while(i<n && j<n)
        {
            if(as[i].first>as[j].second)
            {
                count++;
                j=i;
            }
            i++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends