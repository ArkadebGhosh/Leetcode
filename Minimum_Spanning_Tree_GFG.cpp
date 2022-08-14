/*
Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum Spanning Tree.

*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int src = 0;
        int finalWeight = 0;
        vector<int> weight(V, INT_MAX);
        weight[src] = 0;
        vector<bool> inMST(V, false);
        pq.push({0, src});
        
        while(!pq.empty()) {
            int minNode = pq.top().second;
            int currWt = pq.top().first;
            pq.pop();
            if(inMST[minNode])
            continue;
            inMST[minNode] = true;
            finalWeight+=currWt;
            for(auto &v: adj[minNode]) {
                if(weight[v[0]] > v[1]) {
                    pq.push({v[1], v[0]});
                    weight[v[0]] = v[1];
                }
            }
        }
        return finalWeight;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
