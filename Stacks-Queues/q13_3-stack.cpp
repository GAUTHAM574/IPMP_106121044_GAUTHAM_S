//implementation 1 -- equal space for each stack 
/*
stack will be filled alternatively  that is if size of array is 9[0:8]
stack - 1 : 0 3 6
stack - 2 : 1 4 7
stack - 3 : 2 5 8
*/

class 3stack{
  private : 
    int n;
    int top1 = -3, top2 = -2, top3 = -1;
    vector<int> arr;
  public:
    3stack(int x){
      n = x;
      for(int i = 0 ; i  < n; i++){
        arr.pus_back(-1);
      }
    }
  
    void push_1(int x){
      if(top1 == n-3){return;}
      top1 = top1 + 3;
      arr[top1] = x;
    }
    void push_2(int x){
        if(top2 == n-2){return;}
        top2 = top2 + 3;
        arr[top2] = x;
    }
    void push_3(int x){
        if(top3 == n-1){return;}
        top3 = top3 + 3;
        arr[top3] = x;
    }
    int pop1(){
      if(top1 == n - 3){return -1;}
      int x = arr[top1];
      top1-=3;
      return x;
    }
    int pop2(){
      if(top2 == n - 3){return -1;}
      int x = arr[top2];
      top2-=3;
      return x;
    }
    int pop3(){
      if(top3 == n - 3){return -1;}
      int x = arr[top3];
      top3-=3;
      return x;
    }
};
