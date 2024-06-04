//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        queue<int>q;
        vector<vector<int>>ans;
        q.push(arr[0]);
        ans.push_back({arr[0]});
        for(int i = 1; i<n; i++) {
            int size = q.size();
            size *= 2;
            vector<int>v;
            int c = 0;
            while(size--) {
                c++;
                if(i >= n) {break;}
                if((c&1) == 0) q.pop();
                q.push(arr[i]);
                v.push_back(arr[i]);
                i++;
            }
            i--;
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];

        Solution ob;
        
		vector <vector <int>> res = ob.binTreeSortedLevels (arr, n);
		for (int i = 0; i < res.size(); ++i)
		{
			for (int j = 0; j < res[i].size(); ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends