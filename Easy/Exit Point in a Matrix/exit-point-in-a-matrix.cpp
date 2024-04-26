//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        bool l = false, d = false, r = true, u = false;
        while(i < n && j < m && i >= 0 && j >= 0) {
            if(matrix[i][j] == 0) {
                if(r) j++;
                if(l) j--;
                if(u) i--;
                if(d) i++;
            }
            else{
                matrix[i][j] = 0;
                if(r) {
                    r = false;
                    d = true;
                    i++;
                } 
                else if(l) {
                    l = false;
                    u = true;
                    i--;
                }
                else if(d) {
                    d = false;
                    l = true;
                    j--;
                }
                else if(u) {
                    u = false;
                    r = true;
                    j++;
                }
            }
        }
        if(i < 0) i = 0;
        if(j < 0) j = 0;
        if(i >= n) i = n-1;
        if(j >= m) j = m-1;
        return {i, j};
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends