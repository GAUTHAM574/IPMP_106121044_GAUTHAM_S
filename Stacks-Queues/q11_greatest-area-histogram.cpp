//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long res = arr[0];
        stack<int> s;
        s.push(0);
        int i;
        for(i = 1; i< n; i++){
            while(!s.empty() && arr[s.top()] > arr[i]){
                //res = max(res, arr[i] * (i -  s.top() +1 ));
                int temp = s.top();
                s.pop();
                res = max(res, arr[temp] * (s.empty() ? i :i- s.top() - 1 ));
            }
            s.push(i);
        }
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            res = max(res, arr[temp] * (s.empty() ? i :i- s.top() - 1 ));
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
