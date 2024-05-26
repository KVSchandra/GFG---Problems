//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int solve(int i, int j, string &x, string &y, vector<vector<int>>&dp) {
        if(i == x.size() || j == y.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick = 0;
        if(x[i] == y[j]) pick = 1 + solve(i+1, j+1, x, y, dp);
        int notPick = max(solve(i+1, j, x, y, dp), solve(i, j+1, x, y, dp));
        return dp[i][j] = max(pick, notPick);
    }
  
    int findMinCost(string x, string y, int costX, int costY) {
        vector<vector<int>>dp(x.size(), vector<int>(y.size(), -1));
        int a = solve(0, 0, x, y, dp);
        return (x.size() - a)*costX + (y.size() - a)*costY;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends