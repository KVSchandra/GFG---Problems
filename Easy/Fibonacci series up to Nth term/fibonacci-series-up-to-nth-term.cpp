//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        vector<int> ans;
        long long mod = 1e9+7;
        if (n >= 0) ans.push_back(0ll);
        if (n >= 1) ans.push_back(1ll);
        if (n >= 2) {
            for (long long i = 2; i <= n; i++) {
                long long a = (ans[ans.size() - 1] + ans[ans.size() - 2])%mod;
                ans.push_back((long long)a);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends