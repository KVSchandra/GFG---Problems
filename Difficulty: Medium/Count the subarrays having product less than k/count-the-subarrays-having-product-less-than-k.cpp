//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

#define ll long long
class Solution{
  public:
    long long countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        ll i = 0, j = 0;
        ll prod = 1, count = 0;
        while(j < a.size()) {
            prod *= a[j];
            if(prod < k) {
                count += (j-i+1);;
                j++;
            }
            else {
                while(prod >= k && i <= j) {
                    prod /= a[i];
                    i++;
                }
                count += (j-i+1);
                j++;
            }
        }
        // if(prod < k) {
        //     count += j-i+1;
        // } 
        return count;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends