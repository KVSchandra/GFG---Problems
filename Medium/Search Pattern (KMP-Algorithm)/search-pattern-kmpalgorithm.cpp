//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<int> buildLPS(const string& p){int m=p.length();vector<int> l(m,0);int len=0;for(int i=1;i<m;){if(p[i]==p[len]){len++;l[i]=len;i++;}else{if(len!=0)len=l[len-1];else{l[i]=0;i++;}}}return l;}
vector<int> KMP(const string& t,const string& p){int n=t.length(),m=p.length();vector<int> a,lps=buildLPS(p);int i=0,j=0;while(i<n){if(p[j]==t[i]){j++;i++;}if(j==m){a.push_back(i-j+1);j=lps[j-1];}
else if(i<n&&p[j]!=t[i]){if(j!=0)j=lps[j-1];else i++;}}return a;}
        vector <int> search(string pat, string txt)
        {
            return KMP(txt, pat);
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends