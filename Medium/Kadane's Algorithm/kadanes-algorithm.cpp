//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:

    long long maxSubarraySum(int arr[], int n){
       long maxSum=-1;
        long currsum=0;
        for(int i=0;i<n;i++){
            currsum+=arr[i];
            if(currsum>maxSum){
                maxSum=currsum;
            }
            if(currsum<0){
                currsum=0;
            }
        }
        return    maxSum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends