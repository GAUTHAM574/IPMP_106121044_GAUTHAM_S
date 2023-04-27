//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string str = "";
    int solve(int n){
        int c[n] ;
        bool p[n][n];
        for(int i=0; i< n; i++){
            p[i][i] = true;
        }
        for(int i = 2; i <=n ;i ++ ){
            for(int j = 0 ; j <= n - i  ; j ++){
                int end = i + j -1;
                if(i == 2 ){p[j][end] = str[j] == str[end];}
                else{
                    p[j][end] = str[j] == str[end] && p[j+1][end-1] ;
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(p[0][i] ){
                c[i] = 0;
            }
            else{
                c[i] = INT_MAX;
                for(int j = 0 ;j < i; j++){
                    if(p[j + 1][i] && c[j] + 1 < c[i] ){
                        c[i] = c[j] + 1;
                    }
                }
            }
        }
        return c[n-1];
    }
    int palindromicPartition(string str)
    {
        Solution ::str = str;
        return solve(str.size());
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
