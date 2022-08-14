/*
Implement Dijkstra's algorithm for adjacency list
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> disTo(V, INT_MAX);
        vector<bool> fixed(V, false);
        disTo[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty()) {
            int minVertex = pq.top().second;
            int currWeight = pq.top().first;
            pq.pop();
            if(fixed[minVertex])
            continue;
            fixed[minVertex] = true;
            for(auto &v: adj[minVertex]) {
                if(disTo[v[0]] == INT_MAX || disTo[v[0]] > currWeight + v[1]) {
                    disTo[v[0]] = currWeight + v[1];
                    pq.push({currWeight+v[1], v[0]});
                }
            }
        }
        
        return disTo;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
