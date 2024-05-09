//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

	private:
	int mod = 1e9+7;
    int solver(int index,int *arr,int target,vector<vector<int>>&dp)
    {
        
        if(index==-1)
        {
            if(target==0)
            {
                return 1;
            }
            return 0;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        int notk=solver(index-1,arr,target,dp);
        int t=0;
        if(target>=arr[index])
        {
            t=solver(index-1,arr,target-arr[index],dp);
        }
        return dp[index][target]=(t+notk)%mod;
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solver(n-1,arr,sum,dp);
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