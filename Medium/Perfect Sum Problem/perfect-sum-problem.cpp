//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	public:
	long long mod = 1e9+7;
	int solve(long long i, long long sum, long long n, long long k, int arr[], vector<vector<long long>>& dp) {
        if (i >= n) return (sum == k);
        if (dp[i][sum] != -1) return dp[i][sum];
        long long pick = 0;
        if ((sum + arr[i]) % mod <= k) pick = solve(i + 1, (sum + arr[i]) % mod, n, k, arr, dp);
        long long notPick = solve(i + 1, sum, n, k, arr, dp);
        return dp[i][sum] = (pick + notPick) % mod;
    }

	
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<long long>>dp(n+2, vector<long long>(sum+1, -1));
        return solve(0, 0ll, n, sum, arr, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends