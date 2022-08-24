// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(vector<int> adj[],vector<int> &visited, vector<int> &recstack, int i,int prev){
        visited[i]=1;
        recstack[i]=1;
        for(int j=0;j<adj[i].size();j++){
            if(prev==adj[i][j]) return true;
            if(!visited[adj[i][j]] && dfs(adj,visited,recstack,adj[i][j],i)) 
                return true;
            else if(recstack[adj[i][j]])
                return true;
        }
        recstack[i]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        vector<int> recstack(V,0);
        for(int i=0;i<V;i++)
        if(!visited[i] && dfs(adj,visited,recstack,i,-1))
        return true;
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends