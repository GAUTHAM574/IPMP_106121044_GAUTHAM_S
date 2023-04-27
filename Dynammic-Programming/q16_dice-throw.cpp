//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long noOfWays(int M , int N , int X) {
        vector<vector<long long >>m;
        vector<long long> t (X+1,0);
        for(int i = 0 ;i<=N;i++){m.push_back(t);}
        m[0][0]=1;
        for(int i = 1 ; i <=  N; i++){
            for(int j = i; j <= X; j++){
                m[i][j] = m[i][j-1] + m[i-1][j-1];
                if( j - M - 1 >= 0){
                    m[i][j] -= m[i-1][j-M-1];
                }
            }
        }
        return m[N][X];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends
