int ceilSearch(int A[], int l, int h, int x){
  if(l > h){return -1;}
  if(A[l] >= x){return A[l];}
  if(A[h] < x){return -1;}
  
  int m = (l+h)/2;
  
  if(A[m] == x){return x;}
  
  if(A[m] < x){
    return ceilSearch(A, m+1, h, x);
  if(mid-1 >= l && A[mid-1] < x){return A[mid];}
  return ceilSearch(A, l, m-1, x);
}
  
