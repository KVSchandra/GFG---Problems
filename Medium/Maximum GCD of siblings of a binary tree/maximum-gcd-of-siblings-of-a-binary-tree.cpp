//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int n) {
        unordered_map<int, vector<int>>adj;
        int maxi = INT_MIN;
        for(auto val : arr) {
            adj[val[0]].push_back(val[1]);
            if(adj[val[0]].size() > 1) {
                maxi = max(maxi, __gcd(adj[val[0]][0], adj[val[0]][1]));
            }
        }
        if(maxi == INT_MIN) maxi = 0;
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends