//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

#define ll long long
class Solution{
    public:
    long long ValidPair(int a[], int n) 
    { 
    	ll ans = 0;
    	sort(a, a + n);
    	for(ll i = 0; i < n; i++) {
    	    if(a[i] < 0) {
    	        auto it = upper_bound(a, a+n, (-1)*(a[i]));
    	        if(it != a + n) {
    	            ll idx = it - a;
    	            ans += (n - idx);
    	        }
    	    }
    	    else {
    	        ans += (n-i-1)*(n-i)/2;
    	        break;
    	    }
    	}
    	return ans;
    }   
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int array[n];
		for (int i = 0; i < n; ++i)
			cin>>array[i];
	    Solution obj;
		cout << obj.ValidPair(array, n) <<"\n";
	}
	return 0; 
} 


// } Driver Code Ends