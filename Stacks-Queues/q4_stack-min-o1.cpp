// ListNode structure
struct Node {
  int val;
  Node * next;
  Node * prevMin;
};

//for every node maintaing a prevMin in case the min gets updated or popped

class Stack{
  private:
    Node * head;
    Node * Min;
  public:
    Stack(){
      head = NULL;
      Min = NULL;
    }
    void push(int x);
    int pop();
    int findMin();
    int delete_mid();
};

void Stack::push(int x){
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->val = x;
  newNode->next = head;
  newNode->prevMin = Min;
  head = newNode;
  if(Min == NULL || Min->val > x){
    Min = newNode;
}

int Stack::pop(){
  if(head == NULL){return -1;}
  int x = head->val;
  if(head == Min){
    Min = Min->prevMin;
  }
  head = head->next;
  return x;
}

int Stack::findMin(){
  if(head == NULL){return -1;}
  return Min->val;
}
