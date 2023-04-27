//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<int>> m;
    int solve(int i, int j, string A){
        if(j<i){return 0;}
        if(i == j){return 1;}
        if(m[i][j] == -1){
            if(A[i] == A[j]){
                m[i][j] = 2 + solve(i+1, j-1, A);
            }
            else{
                m[i][j] = max(solve(i, j-1, A), solve(i+1, j, A));
            }
        }
        return m[i][j];
    }
    int longestPalinSubseq(string A) {
        vector<int> temp(A.length(), -1);
        for(int i = 0; i < A.length() ; i++){
            m.push_back(temp);
        }
        return solve(0,A.length()-1,A);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
