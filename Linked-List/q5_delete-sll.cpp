#include<stdio.h>
#include<stdlib.h>

struct  node 
{
    int data;
    struct node * next;
};

void main()
{
    struct node *head=NULL;

    void insert_s()
    {
        int data;
        printf("\nEnter data : ");
        scanf("%d",&data);
        struct node * new=(struct node*)malloc(sizeof(struct node ));
        new->data=data;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            return;
        }
        new->next=head;
        head=new;
        return;
    }

    void insert_l()
    {
        int data;
        printf("\nEnter data : ");
        scanf("%d",&data);
        struct node * new=(struct node*)malloc(sizeof(struct node ));
        new->data=data;
        new->next=NULL;
        if(head==NULL)
        {
            head=new;
            return;
        }
        struct node * current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=new;
        return;
    }
    void insert_k()
    {
        int k;
        printf("\nEnter position : ");
        scanf("%d",&k);
        if(k==1 || head==NULL)
        {
            insert_s();
            return;
        }
        int data;
        printf("\nEnter data : ");
        scanf("%d",&data);
        struct node * new=(struct node*)malloc(sizeof(struct node ));
        new->data=data;
        new->next=NULL;
        struct node * current=head;
        int i=1;
        while(i<k-1 && current->next!=NULL)
        {
            current=current->next;
            i++;
        }
        if(current->next==NULL)
        {
            current->next=new;
            return;
        }
        new->next=current->next;
        current->next=new;
        return;
    }

    void del_s()
    {
        struct node * temp=head;
        head=head->next;
        printf("\n%d is deleted from the double linked list\n",temp->data);
        free(temp);
        return;
    }

    void del_l()
    {
        struct node * current=head;
        while(current->next->next!=NULL)
        {
            current=current->next;
        }
        struct node * temp=current->next;
        printf("\n%d is deleted from the double linked list\n",temp->data);
        free(temp);
        current->next=NULL;
        return;
    }

    void del_k()
    {
        int k;
        printf("Enter position : ");
        scanf("%d",&k);
        if(k==1)
        {
            del_s();
            return;
        }
        struct node * current=head;
        int i=0;
        while(i<k-2 && current->next->next!=NULL)
        {
            current=current->next;
            i++;
        }
        if(current->next->next==NULL)
        {
            printf("\n%d is deleted from the double linked list\n",current->next->data);
            free(current->next);
            current->next=NULL;
            return;
        }
        struct node * temp=current->next;
        current->next=current->next->next;
        printf("\n%d is deleted from the double linked list\n",temp->data);
        free(temp);

        return;
    }

    void display()
    {
        struct node *current=head;
        while(current->next!=NULL)
        {
            printf("\t%d\t",current->data);
            current=current->next;
        }
        printf("\t%d\t",current->data);
        return;
    }

    int temp=0;
    while(1)
    {
        int choice;
        printf("\nCHOICES\n1)Insert at begining\n2)Insert at last\n3)Insert at kth position\n4)Delete from begining\n5)Delete from last\n6)Delete at kth position\n7)Display\n8)EXIT...\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                insert_s();
                printf("\nInsert_at_start()\n");
                break;
    
            case 2:
                insert_l();
                printf("\nInsert_at_end()\n");
                break;

            case 3: 
                insert_k();
                printf("\nInsert_at_k()\n");
                break;

            case 4: 
                if(head==NULL)
                {
                    printf("\nLinked List is EMPTY\n");
                    break;
                }
                del_s();
                printf("\nDelete_at_start()\n");
                break;
        
            case 5:
                if(head==NULL)
                {
                    printf("\nLinked List is EMPTY\n");
                    break;
                }
                del_l();
                printf("\nDelete_at_end()\n");
                break;

            case 6: 
                if(head==NULL)
                {
                    printf("\nLinked List is EMPTY\n");
                    break;
                }
                del_k();
                printf("\nDelete_at_k()\n");
                break;

            case 7:
                printf("\nThe Single Linked List is \n");
                display();
                printf("\n\n\n");
                break;

            case 8 : 
                temp=1;
                printf("EXIT()");
                break;
            }
            if(temp==1)
                    break;
        }
    void del_all()
    {
        struct node *current=head;
        while(current->next!=NULL)
        {
            printf("\t%d\t",current->data);
            struct node *temp=current;
            current=current->next;
            free(temp);
        }
        printf("\t%d\t",current->data);
        free(current);
        return;
    }
    printf("\nFINAL RESULT\n");
    del_all();
    printf("\nThe single linked List\nprocess is now terminated ....\nThanks for using.\n\n");
    return;
}
