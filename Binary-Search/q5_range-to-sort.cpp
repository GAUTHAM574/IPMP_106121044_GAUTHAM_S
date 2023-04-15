//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    int l, r;
	    vector<int> res ;
	    for(l = 0; l < n-1 ; l++){
	        if(arr[l] > arr[l+1]){break;}
	    }
	    for(r = n-1; r>=1; r--){
	        if(arr[r] < arr[r-1]){break;}
	    }
	    res.push_back(l);
	    res.push_back(r);
	    if( l == n-1 && r == 0){
	       return res;
	    }
	    int min = INT_MAX;
	    int max = INT_MIN;
	    for(int i = l; i <= r; i++){
	        if(min > arr[i]){
	            min = arr[i];
	        }
	        if(max < arr[i]){
	            max = arr[i];
	        }
	    }
	    for(int i = 0; i < l; i++){
	        if(min < arr[i]){
	            res[0] = i;
	            break;
	        }
	    }
	    for(int i = n-1; i > r; i--){
	        if(max > arr[i]){
	            res[1] = i;
	            break;
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}

// } Driver Code Ends
