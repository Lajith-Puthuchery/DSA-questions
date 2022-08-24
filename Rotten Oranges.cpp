// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int i, int j,vector<vector<int>>&grid) {
        return (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size());
    }
    bool isdelim(pair<int,int> temp) {
        return  (temp.first==-1 && temp.second==-1);
    }
    bool checkall(vector<vector<int>>&grid) {
        for(auto x : grid) {
            for(auto y : x) {
                if(y==1) {
                    return false;
                }
            }
        }
        return true;
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        // Code here
        queue<pair<int,int>> q;
        pair<int,int> temp;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j]==2) {
                    q.push(make_pair(i,j));
                }
            }
        }
        q.push(make_pair(-1,-1)); //delimitter to separate time
        while(!q.empty()) {
            bool flag = false;
            while(!isdelim(q.front())) {
               temp = q.front();
                while(isValid(temp.first+1,temp.second,grid) && grid[temp.first+1][temp.second]==1) {
                    if(!flag)
                        ans++,flag=true;
                        grid[temp.first+1][temp.second]=2;
                        q.push(make_pair(temp.first+1,temp.second));
                }
                while(isValid(temp.first-1,temp.second,grid) && grid[temp.first-1][temp.second]==1) {
                    if(!flag)
                        ans++,flag=true;
                        grid[temp.first-1][temp.second]=2;
                        q.push(make_pair(temp.first-1,temp.second));
                }
                while(isValid(temp.first,temp.second+1,grid) && grid[temp.first][temp.second+1]==1) {
                    if(!flag)
                        ans++,flag=true;
                        grid[temp.first][temp.second+1]=2;
                        q.push(make_pair(temp.first,temp.second+1));
                }
                while(isValid(temp.first,temp.second-1,grid) && grid[temp.first][temp.second-1]==1) {
                    if(!flag)
                        ans++,flag=true;
                        grid[temp.first][temp.second-1]=2;
                        q.push(make_pair(temp.first,temp.second-1));
                }
                q.pop();                
            }
            q.pop();
            if(!q.empty()) {
                q.push(make_pair(-1,-1));
            }
        }
        return checkall(grid) ? ans : -1;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends