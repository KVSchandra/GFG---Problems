//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long
class Solution{
    public:
    long long required(long long arr[], long long n, long long k) {
        ll maxi = -1;
         for(int i = 0; i < n; i++) {
             if(arr[i] > k) {
                 maxi = max(maxi, (ll)arr[i] - k);
             }
         }
         return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        long long arr[n];
        for (long long i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        cout << ob.required(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends