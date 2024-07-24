//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int, int>> adj[n];
        for(auto val : flights) {
            adj[val[0]].push_back({val[1], val[2]});
        }
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[src] = 0;
        pq.push({0, {0, src}});
        while(!pq.empty()) {
            int node = pq.top().second.second;
            int cost = pq.top().second.first;
            int a = pq.top().first;
            pq.pop();
            if(a > k) continue;
            for(auto val : adj[node]) {
                int adjNode = val.first;
                int edgeWt = val.second;
                if(a <= k) {
                    if(dist[adjNode] > edgeWt + cost) {
                        dist[adjNode] = edgeWt + cost;
                        pq.push({a + 1, {dist[adjNode], adjNode}});
                    }
                }
            }
        }
        if(dist[dst] != INT_MAX) return dist[dst];
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends