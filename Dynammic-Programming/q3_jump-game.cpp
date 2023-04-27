//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int canReach(int nums[], int n) {
        //int n = nums.size();
        int dp[n];
        dp[n-1] = 0;
        for(int i = n-2; i>=0; i--){
            if(nums[i] == 0){dp[i] = INT_MAX;}
            if(nums[i] + i  >= n -1 ){dp[i] = 1;}
            else{
                int temp = INT_MAX ;
                for(int j = i + 1; j < n && j <= nums[i] + i ; j++){
                    if( temp > dp[j]){
                        temp = dp[j];
                    }
                }
                if(temp == INT_MAX)
                    dp[i] = INT_MAX;
                else
                    dp[i] = 1 + temp;
            }
            //cout<<dp[i]<<" ";
        }
        return dp[0] != INT_MAX ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends
