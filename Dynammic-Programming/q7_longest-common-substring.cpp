//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    string s1, s2;
    int Solve(int n, int m){
        
    }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int arr[n+1][m+1];
        int res = 0;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m ; j++){
                if(i == 0|| j == 0){
                    arr[i][j] = 0;
                }
                else if( S1[i-1] == S2[j-1]){
                    arr[i][j] = 1 + arr[i-1][j-1];
                    res = max(res, arr[i][j]);
                }
                else{
                    arr[i][j] = 0;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
