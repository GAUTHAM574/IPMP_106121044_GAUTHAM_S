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
      if(top1 == -3){return -1;}
      int x = arr[top1];
      top1-=3;
      return x;
    }
    int pop2(){
      if(top2 == - 2){return -1;}
      int x = arr[top2];
      top2-=3;
      return x;
    }
    int pop3(){
      if(top3 == -1 ){return -1;}
      int x = arr[top3];
      top3-=3;
      return x;
    }
};

//Implementation -2
//Allocating n/2 for one stack and other n/2 for remaining two stacks
/*
[0:n-1]

stack 1 : [0 : (n-1)/2 ]
stack 2 : [(n-1)/2 + 1 : x ]
stack 3 : [ x+1 : n-1 ]

where mid + 1 <= x <= n-1
*/
class 3Stack_2{
  private :
    int n;
    int top1 = -1, top2 , top3;
    vector<int> arr;
  public:
    3Stack_2(int x){
      n = x;
      top3 = n;
      top2 = (n-1) / 2;
      for(int i = 0 ; i  < n; i++){arr.pus_back(-1);}
    }
    void push1(int);
    void push2(int);
    void push3(int);
    int pop1();
    int pop2();
    int pop3();
};


void push1(int x){
    if(top1 == (n-1)/2){return;}
    arr[++top1] = x;
}
void push2(int x){
    if(top2  == top3 - 1 ){return;}
    arr[++top2] = x;
}
void push3(int x){
    if(top3 == top2 + 1){return;}
    arr[--top3] = x;
}
int pop1(){
  if(top1 == -1){return -1;}
  int x = arr[top1--];
  return x;
}
int pop2(){
  if(top2 == (n - 1)/2){return -1;}
  int x = arr[top2--];
  return x;
}
int pop3(){
  if(top3 == n ){return -1;}
  int x = arr[top3++];
  return x;
}
