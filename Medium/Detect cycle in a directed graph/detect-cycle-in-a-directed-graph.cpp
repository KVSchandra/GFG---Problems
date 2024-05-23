//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    vector<int> topoSort(vector<int>&inDegree, vector<int>adj[]) {
        vector<int>topo;
        queue<int>q;
        for(int i = 0; i<inDegree.size(); i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto val : adj[node]) {
                inDegree[val]--;
                if(inDegree[val] == 0) {
                    q.push(val);
                }
            }
        }
        return topo;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>inDegree(V, 0);
        for(int i = 0; i<V; i++) {
            for(auto val : adj[i]) {
                inDegree[val]++;
            }
        }
        vector<int>topo = topoSort(inDegree, adj);
        // for(auto val : topo) cout << val << " ";
        return (topo.size() != V);
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