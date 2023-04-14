//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int pivotFind(int A[], int l , int h){
        if(l>h){return -1;}
        int m = (l + h)/2;
        if(A[m] > A[m+1]){return m;}
        if(A[m] < A[m-1]){return m-1;}
        if(A[l] >= A[m]){
            return pivotFind(A, l, m-1);
        }
        return pivotFind(A, m+1, h);
    }
    int bSearch(int A[], int l, int h, int key){
        if(l>h){return -1;}
        int m = (l + h) / 2;
        if(A[m] == key){return m;}
        if(key > A[m]){return bSearch(A, m+1, h, key);}
        return bSearch(A, l , m-1, key);
    }
    int search(int A[], int l, int h, int key){
        int pivot = pivotFind(A, l , h);
        if(pivot == -1 && key > A[h]){return -1;}
        if(pivot == -1 && key < A[l]){return -1;}
        if(pivot == -1){return bSearch(A, l, h, key);}
        if(A[pivot] == key){return pivot;}
        if(key < A[l]){ return bSearch(A, pivot +1 , h , key);}
        return bSearch(A, l , pivot-1, key);
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends
