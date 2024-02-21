//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/
int mod = 1e9 + 7;
class Solution
{
    public:
    int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){
        if(i >= s.size() && j < t.size()) return 0;
        if(j == t.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int pick = 0;
        if(s[i] == t[j]){
            pick = (solve(i+1, j+1, s, t, dp)%mod);
        }
        int notPick = 0 + (solve(i+1, j, s, t, dp)%mod) ;
        return dp[i][j] = (pick + notPick)%mod;
    }
    
    int subsequenceCount(string s, string t)
    {
        vector<vector<int>>dp(s.size(), vector<int>(t.size(), -1));
        return (solve(0, 0, s, t, dp)%mod);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends