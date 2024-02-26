//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(int i, string temp, vector<string>&ans, string &s){
	        if(i == s.size()) {if (temp != "") ans.push_back(temp); return;}
	        
	        temp += s[i];
	        solve(i+1, temp, ans, s);
	        temp.pop_back();
	        solve(i+1, temp, ans, s);
	        return;
	        
	    }
	
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    solve(0, "", ans, s);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends