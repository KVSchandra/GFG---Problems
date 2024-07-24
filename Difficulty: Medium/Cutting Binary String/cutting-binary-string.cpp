//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define ll long long
class Solution{
    public:
    bool check(string& temp) {
        reverse(temp.begin(), temp.end());
        long long x = 0ll;
        for(ll i = 0; i < temp.size(); i++) {
            if(temp[i] == '1') {
                x += (1ll << i);
            }
        }
        if(x == 0) return false;
        while(x % 5 == 0) {
            x /= 5;
            if(x % 5 != 0 && x != 1) return false;
        }
        return (x == 1);
    }
    
    int solve(int i, string& s, vector<ll>& dp) {
        if(i >= s.size()) return 0; 
        if(i == s.size() - 1) return 1;
        if(dp[i] != -1) return dp[i];
        ll mini = LLONG_MAX;
        for(ll j = i; j < s.size(); j++) {
            string temp = s.substr(i, j-i+1);
            if(check(temp)) {
                mini = min(mini, (ll)1 + solve(j+1, s, dp));
            }
        }
        return dp[i] = mini;
    }
    
    int cuts(string s){
        vector<ll> dp(s.size()+1, -1);
        ll ans = solve(0, s, dp);
        return (ans == LLONG_MAX ? -1 : ans);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   string s;
   while(t--)
   {
    cin>>s;
    Solution obj;
    int res=obj.cuts(s);
    cout<<res<<endl;

   }


    return 0;
}

// } Driver Code Ends