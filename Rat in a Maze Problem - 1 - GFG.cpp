// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void maze(vector<vector<int>> &m, int n, string dir, vector<string> &result, 
        vector<vector<int>> &vis, int i, int j)
    {
        vis[i][j]=1;
        if(i==(n-1) && j==(n-1))
        {
            result.push_back(dir);
            vis[i][j]=0;
            return;
        }
        string intermediate=dir;
        if(i+1<n && m[i+1][j]==1 && vis[i+1][j]==0)
        {
            dir+="D";
            maze(m, n, dir, result, vis, i+1, j);
        }
        dir=intermediate;
        if(j+1<n && m[i][j+1]==1 && vis[i][j+1]==0)
        {
            dir+="R";
            maze(m, n, dir, result, vis, i, j+1);
        }
        dir=intermediate;
        if(i-1>=0 && m[i-1][j]==1 && vis[i-1][j]==0)
        {
            dir+="U";
            maze(m, n, dir, result, vis, i-1, j);
        }
        dir=intermediate;
        if(j-1>=0 && m[i][j-1]==1 && vis[i][j-1]==0)
        {
            dir+="L";
            maze(m, n, dir, result, vis, i, j-1);
        }
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        string dir="";
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<string> result;
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return {"-1"};
        maze(m, n, dir, result, vis, 0, 0);
        sort(result.begin(), result.end());
        return result;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends