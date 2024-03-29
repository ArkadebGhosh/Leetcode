//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  bool dfs(int v,  vector<int> adj[], vector<int> &visited, vector<int>&path) {
      visited[v] = 1;
      path[v] = 1;
      for(auto &neigh: adj[v]) {
          if(path[neigh] == 1)
          return true;
          else if(!visited[neigh] && dfs(neigh, adj, visited, path))
          return true;
      }
      path[v] = 0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V, 0);
        vector<int> path(V, 0);
        for(int i = 0; i<V; i++) {
            if(!visited[i] && dfs(i, adj, visited, path))
            return true;
        }
        return false;
    }
};

//{ Driver Code Starts.

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