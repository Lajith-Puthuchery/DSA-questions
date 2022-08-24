//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    static bool sortbysec(const pair<int,int> a, const pair<int,int> b)
    {
        return (a.second<b.second);
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> maxmeeting;
        pair<int,int> p;
        for(int i=0; i<n; i++)
        {
            p.first=start[i];
            p.second=end[i];
            maxmeeting.push_back(p);
        }
        sort(maxmeeting.begin(), maxmeeting.end(), sortbysec);
        int count=1;
        int i=1, j=0;
        while(i<n && j<n)
        {
            if(maxmeeting[i].first>maxmeeting[j].second)
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends