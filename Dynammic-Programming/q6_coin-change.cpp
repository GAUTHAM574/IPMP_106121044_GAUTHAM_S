//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {

        long long m[sum+1][n];
        for(int i = 0; i < n; i++){
            m[0][i] = 1;
        }
        for(int i= 1; i < sum+1; i++){
            for(int j = 0; j < n; j++){
                long long x, y;
                if(i - coins[j] >= 0){x = m[i - coins[j]][j];}
                else{x = 0;}
                
                if(j >= 1){y = m[i][j-1];}
                else{y=0;}
                m[i][j] = x + y;
            }
        }
        return m[sum][n-1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
