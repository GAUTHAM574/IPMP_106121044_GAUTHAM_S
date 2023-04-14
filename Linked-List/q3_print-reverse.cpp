/*
  NODE STRUCTURE
  struct Node{
    int val;
    Node * next;
  };
*/

void print(Node * node){
  if(node == NULL){ return;}
  print(node->next);
  cout<<node->val;
  return;
}

  
