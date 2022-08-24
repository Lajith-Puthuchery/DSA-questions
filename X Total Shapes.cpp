//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void compute(vector<vector<char>>& grid, vector<vector<int>> &vis,
        int n, int m, int i, int j)
    {
        vis[i][j]=1;
        if(i-1>=0 && grid[i-1][j]=='X' && vis[i-1][j]==0)
        {
            compute(grid, vis, n, m, i-1, j);
        }
        if(j-1>=0 && grid[i][j-1]=='X' && vis[i][j-1]==0)
        {
            compute(grid, vis, n, m, i, j-1);
        }
        if(i+1<n && grid[i+1][j]=='X' && vis[i+1][j]==0)
        {
            compute(grid, vis, n, m, i+1, j);
        }
        if(j+1<m && grid[i][j+1]=='X' && vis[i][j+1]==0)
        {
            compute(grid, vis, n, m, i, j+1);
        }
    }
    
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int result=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='X')
                {
                    compute(grid, vis, n, m, i, j);
                    result++;
                }
            }
        }
        return result;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends