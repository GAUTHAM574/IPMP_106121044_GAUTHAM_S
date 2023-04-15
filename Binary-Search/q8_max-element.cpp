//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int solve(int arr[], int l, int r){
	    if(l == r){return r;}
	    int m = (l + r)/2;
	    if(arr[m] > arr[m+1] && arr[m] > arr[m-1]){return m;}
	    if(arr[m+1] > arr[m]){return solve(arr, m+1, r);}
	    return solve(arr, l, m-1);
	}
	int findMaximum(int arr[], int n) {
	    int i = solve(arr, 0, n-1);
	    return arr[i];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
