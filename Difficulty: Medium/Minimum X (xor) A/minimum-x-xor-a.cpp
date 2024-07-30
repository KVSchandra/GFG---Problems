//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        int n = __builtin_popcount(b);
        int x = 0;
        for(int i = 31; i >= 0; i--) {
            if(a & (1 << i)) {
                x |= (1 << i);
                n--;
                if(n == 0) break;
            }
        }
        if(n)
            for(int i = 0; i < 31; i++) {
                if((x & (1 << i)) == 0) {
                    n--;
                    x |= (1 << i);
                    if(n == 0) break;
                }
            }
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends