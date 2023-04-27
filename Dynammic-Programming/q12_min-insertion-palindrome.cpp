//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string S){
        int n = S.size();
        vector<int>temp(n,0);
        vector<vector<int>> arr(n,temp) ;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j + i < n; j ++){
                arr[j][i+j] = S[j] == S[ i + j] ? arr[j+1][j+i-1] : min(arr[j + 1][j+i] , arr[j][ j + i - 1]) +1;
            }
        }
        return arr[0][n-1];
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
