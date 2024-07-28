//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int mod = 1e9+7;
class Solution {
    vector<bool> vis;
    int solve(int idx, int k, int n, vector<int>& arr) {
        vis[idx] = 1;
        int i = idx-1, j = idx+1;
        int count1 = 1, count2 = 1;
        while(i >= 0 && !vis[i]) {
            count1++;
            i--;
        }
        while(j < n && !vis[j]) {
            count2++;
            j++;
        }
        return (count1 % mod * (count2 * k) % mod) % mod;
    } 
    
public:
    int sumSubarrayMins(int n, vector<int> &arr) {
        vis.resize(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({arr[i], i});
        }
        int ans = 0;
        while(!pq.empty()) {
            ans = (ans + solve(pq.top().second, pq.top().first, n, arr)) % mod;
            pq.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.sumSubarrayMins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends