//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        int m[n+1][n+1];
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0; j <= n ; j++){
                if(i == 0 || j == 0){m[i][j] = 0;}
                else if( i<=j ){
                    m[i][j] = max(m[i-1][j] , m[i][j - i] + price[i-1]);
                }
                else{
                    m[i][j] = m[i-1][j];
                }
            }
        }
        return m[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
