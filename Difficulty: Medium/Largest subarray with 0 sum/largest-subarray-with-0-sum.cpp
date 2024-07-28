//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        vector<int> prefix(n);
        map<int, int> mp;
        prefix[0] = arr[0];
        int maxi = 0;
        mp[prefix[0]] = 0;
        if(prefix[0] == 0) {
            maxi = max(maxi, 1);
        }
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + arr[i];
            if(mp.find(prefix[i]) == mp.end()) {
                mp[prefix[i]] = i;
            }
            else {
                maxi = max(maxi, abs(i - mp[prefix[i]]));
            }
            if(prefix[i] == 0) {
                maxi = max(maxi, i+1);
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends