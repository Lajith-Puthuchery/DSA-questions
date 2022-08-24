// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        set<vector<int>>st;
        vector<int> quadruple;
        for(int i=0; i<arr.size()-3; i++)
        {
            for(int j=i+1; j<arr.size()-2; j++)
            {
                int low=j+1;
                int high=arr.size()-1;
                while(low<high)
                {
                    vector<int> quadruple;
                    if(arr[i]+arr[j]+arr[low]+arr[high]==k)
                    {
                        quadruple.push_back(arr[i]);
                        quadruple.push_back(arr[j]);
                        quadruple.push_back(arr[low]);
                        quadruple.push_back(arr[high]);
                        st.insert(quadruple);
                        low++;
                        high--;
                    }
                    else if(arr[i]+arr[j]+arr[low]+arr[high]>k)
                        high--;
                    else
                        low++;
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends