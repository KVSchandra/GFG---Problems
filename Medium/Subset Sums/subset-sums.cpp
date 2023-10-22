//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int ind,vector<int>&arr,int N,vector<int>&v,int sum){
        if(ind == N){
            v.push_back(sum);
            return;
        }
        solve(ind+1,arr,N,v,sum+arr[ind]);
        solve(ind+1,arr,N,v,sum);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>v;
        solve(0,arr,N,v,0);
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends