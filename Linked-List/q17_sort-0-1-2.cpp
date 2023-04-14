/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

Node* sortList(Node *head)
{
    Node * curr = head;
    Node * fake0 = (Node*) malloc(sizeof(Node));
    fake0->next = NULL;
    Node * fake1 = (Node*) malloc(sizeof(Node));
    fake1->next = NULL;
    Node * fake2 = (Node*) malloc(sizeof(Node));
    fake2->next = NULL;
    Node * arr[3]={fake0,fake1,fake2};
    while(curr!=NULL){
        switch(curr->data){
            case 0:
                fake0->next = curr;
                fake0 = curr;
                break;
            case 1:
                fake1->next = curr;
                fake1 = curr;
                break;
            case 2:
                fake2->next = curr;
                fake2 = curr;
                break;
        }
        curr = curr->next;
    }
    fake0->next = arr[1]->next;
    fake1->next = arr[2]->next;
    fake2->next = NULL;
    return arr[0]->next;
}
