//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	
	int bSearch(int arr[], int x, int left,int right){
	    if( right < left){return -1;}
	    int m = (left + right)/2;
	    if(arr[m] == x){return m;}
	    if(arr[m] < x){return bSearch(arr, x, m+1, right);}
	    if(arr[m] > x){return bSearch(arr, x, left, m -1);}
	}
	int count(int arr[], int n, int x) {
	    int ind = bSearch(arr, x, 0 , n-1);
	    if(ind == -1){return 0;}
	    int left = ind-1, right = ind+1, count = 1;
	    while( left>=0 && arr[left] == x){
	        count ++;
	        left --;
	    }
	    while( right<n && arr[right] == x){
	        count ++;
	        right ++;
	    }
	    return count;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends