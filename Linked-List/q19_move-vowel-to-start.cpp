//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/
// task is to complete this function
// function should return head to the list after making 
// necessary arrangements

bool isVowel(char x){
    if( x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ){return true;}
    return false;
}

struct Node* arrange(Node *head)
{
   Node * curr = head;
   Node * cHead = (Node*)malloc(sizeof(Node));
   Node * vHead = (Node*)malloc(sizeof(Node));
   vHead->next = NULL;
   cHead->next = head;
   Node * prevCons = cHead;
   Node * prevVowel = vHead;
   while(curr){
       if(isVowel(curr->data)){
           prevVowel->next = curr;
           prevCons->next = curr->next;
           prevVowel = curr;
       }
       else{
           prevCons = prevCons->next;
       }
       curr = curr->next;
   }
   prevVowel->next = cHead->next;
   prevCons->next = NULL;
   return vHead->next;
}
