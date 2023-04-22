// ListNode structure
struct Node {
  int val;
  Node * next;
};


class Stack{
  private:
    Node * head;
  public:
    Stack(){
      head = NULL;
    }
    void push(int x);
    int pop();
    int middle();
    int delete_mid();
};

void Stack::push(int x){
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->val = x;
  newNode->next = head;
  head = newNode;
}

int Stack::pop(){
  if(head == NULL){return -1;}
  int x = head->val;
  head = head->next;
  return x;
}

//In case of even length return the first middle;
int Stack::middle(){
  if(head == NULL){return -1;}
  Node * curr = head;
  Node * curr2 = head->next;
  while(curr2->next!=NULL ){
    curr = curr->next;
    curr2 = curr2->next->next;
  }
  return curr->val;
}

int Stack::delete_mid(){
  if(head == NULL || head->next == NULL){return -1;}
  Node * dummy = new Node;
  dummy->next = head;
  Node * prev = dummy;
  Node * curr = head;
  Node * curr2 = head->next;
  while(curr2->next!=NULL ){
    prev = curr;
    curr = curr->next;
    curr2 = curr2->next->next;
  }
  int x = curr->val;
  prev ->next = curr->next;
  head = dummy->next;
  return x;
}
