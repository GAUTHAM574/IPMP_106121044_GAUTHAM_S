/* EXPLANATION

first pushing all the machines first node to min heap and increating their heads to next node
poping the top of the heap and pushing the node value to the resultant array
if top's next node is not null then pushing the next nde in tho the heap 
if null then simply continue with next iteration
continue till no element is left in the heap

*/

// struct Node {
//   int data;
//   Node * next;
// };

class Solve{
  public:
//     struct compare{
//       bool operator()(pair<int,Node *> a, pair<int,Node *> b ){
//         return a.second->data > b.second->data;
//       }
//     };
    vector<int> sort_machines( vector<Node *> machine ){
      vector<int>res;
      priority_queue< pair<int,int> , vector<pair<int,int >> , greater<pair<int, int> > pq;
      int n = machine.size();
      //inserting all first nodes of all machines into heap and incrementing to their next node
      for(int i = 0; i < n; i++ ){
        pq.push({machine[i]->data, i});
        machine[i] = machine[i]->next;
      }
      while(!pq.empty() ){
        pair<int,int> t = pq.top();
        pq.pop();
        res.push_back(t.first);
        if( machine[t.second] !=NULL ){
          pq.push( {machine[t.second]->data, t.second} ) ;
          machine[t.second] = machine[t.second]->next;
        }
      }
      return res;
    }
};
