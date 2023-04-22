vector<int> solve(vector<int>arr, int n){
  vector<int>res(n,1);
  stack<int> s;
  s.push(0);
  for(int i = 1; i < n ; i++){
    while(!s.empty() && arr[s.top] <= arr[i]){
      s.pop();
    }
    s[i] = s.empty() ? i+1 :i - s.top();
    s.push(i);
  }
  return res;
}
