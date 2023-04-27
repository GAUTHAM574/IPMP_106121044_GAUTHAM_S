//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int  n;
    string res="";
    void solve(string s, int i, int j){
        while(i>=0 && j < n){
            if(s[i] != s[j]){break;}
            i -- ;
            j ++;
        }
        if(res.size() < j - i){
            res = s.substr(i+1,j-i-1);
        }
    }
    string longestPalindrome(string S){
        n = S.size();
        for(int i = n-1; i >=0 ; i--){
            solve(S,i,i);
            solve(S,i,i+1);
        }
        return res;
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
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
