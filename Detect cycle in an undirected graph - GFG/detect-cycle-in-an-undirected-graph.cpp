//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int v, int parent, vector<int> adj[], vector<int> &visited) {
        visited[v] = 1;
        for(auto &neigh: adj[v]) {
            if(neigh == parent)
                continue;
            if(visited[neigh] == 1)
                return true;
            else if(dfs(neigh, v, adj, visited))
                return true;
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int parent = -1;
        vector<int> visited(V, 0);
        for(int i = 0; i<V; i++) {
            if(!visited[i] && dfs(i, parent, adj, visited))
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends