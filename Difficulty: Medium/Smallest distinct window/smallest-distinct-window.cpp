//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        unordered_set<char> st;
        for(auto val : str) {
            st.insert(val);
        }
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int mini = INT_MAX;
        while(j < str.size()) {
            mp[str[j]]++;
            if(mp.size() < st.size()) {
                j++;
            }
            else {
                while(mp.size() == st.size()) {
                    mp[str[i]]--;
                    mini = min(mini, j-i+1);
                    if(mp[str[i]] == 0) {
                        mp.erase(str[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        if(mp.size() == st.size()) {
            mini = min(mini, j-i+1);
        }
        return mini;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends