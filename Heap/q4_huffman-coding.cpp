//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    struct Node{
	        int freq;
	        char c;
	        Node * l, * r;
	    };
	    vector<string> res;
	    Node * newNode(char data, int freq){
	        Node * newNode= (Node *)malloc(sizeof(Node));
	        newNode->l = NULL;
	        newNode->r = NULL;
	        newNode->c = data;
	        newNode->freq = freq;
	        return newNode;
	    }
	    
	    struct compFunc{
	        bool operator()(Node * a, Node * b){
	            return a->freq > b->freq;
	        }
	    };
	    
	    void createString(Node * p, string i){
	        if(p == NULL){return;}
	        if(p->c == '*'){
	            createString(p->l, i + '0');
	            createString(p->r, i + '1');
	        }
	        else{
	            res.push_back(i);
	        }
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    Node * left, * right, * root;
		    priority_queue< Node* , vector<Node*> , compFunc > pq;
		    for(int i = 0; i < N; i++){
		        pq.push(newNode(S[i], f[i]));
		    }
		    while( pq.size()!= 1){
		        left = pq.top();
		        pq.pop();
		        right = pq.top();
		        pq.pop();
		        
		        root = newNode('*' , left->freq + right->freq );
		        pq.push(root);
		        root->l = left;
		        root->r = right;
		    }
		    createString(pq.top() , "");
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
