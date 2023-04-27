//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> m;
    int solve(int i, int j,int arr[]){
        if(i == j){
            m[i][j] = 0;
            return 0;
        }
        if(m[i][j] == -1){
            int temp = INT_MAX;
            int mul = arr[i-1]*arr[j];
            for(int k = i; k < j; k++ ){
                temp =min ( temp, solve(i, k,arr) + mul * arr[k] + solve(k+1, j,arr) );
            }
            m[i][j] = temp;
        }
        return m[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<int> temp(N, -1);
        for(int i = 0; i < N; i++){
            m.push_back(temp);
        }
        return solve(1,N-1,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
