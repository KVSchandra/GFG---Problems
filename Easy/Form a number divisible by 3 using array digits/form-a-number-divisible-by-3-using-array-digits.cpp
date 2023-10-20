//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int sum(int n){
      int s = 0;
      while(n){
          s+=n%10;
          n/=10;
      }
      return s;
  }
    int isPossible(int N, int arr[]) {
        int Sum=0;
        for(int i = 0;i<N;i++){
            Sum+=sum(arr[i]);
        }
        if(Sum%3 == 0) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends