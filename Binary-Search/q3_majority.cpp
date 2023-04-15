
int firstocc(int A[], int l, int h, int x)
{
  if(l>h){return -1;}
  int m = (l + h)/2;
  if(A[m-1]!=x){return m;}
  if(A[m] >= x){
    return firstocc(A, l , m-1, x);
  }
  return firstocc(A, m +1 , h, x);
}

bool check(int A[], int l, int h, int x){
  int i = firstocc(A,l,x,h);
  //x is not in the array 
  if(i == -1){return false;}
  
  //checking if majority
  if( i + (h-l+1)/2 <= (h-l) && A[i + (h-l+1)/2] == x){return true;}
  return false;
}
