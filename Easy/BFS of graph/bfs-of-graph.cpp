//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    void bfs(int i, vector<int>&vis, vector<int>adj[], vector<int>&ans) {
        queue<int>q;
        q.push(i);
        ans.push_back(i);
        vis[i] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto val : adj[node]) {
                if(!vis[val]) {
                    vis[val] = 1;
                    q.push(val);
                    ans.push_back(val);
                }
            }
        }
    }
    
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>vis(V, 0);
        vector<int>ans;
        bfs(0, vis, adj, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends