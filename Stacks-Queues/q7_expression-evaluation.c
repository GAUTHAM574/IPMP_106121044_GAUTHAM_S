#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[100];
int top=-1;

void push_(char c)
{
    stack[++top]=c;
}

char pop_()
{
    return stack[top--];
}

int pre(char c)
{
    if(c=='(')
        return 0;
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
}

void main()
{
    char infix[100],postfix[100];
    char *i=infix;
    int j=-1;
    printf("Enter input : ");
    scanf("%s",infix);
    char temp;
    while(*i!='\0')
    {
        if(isalnum(*i))
        {
            printf("%c",*i);
            postfix[++j]=*i;
        }
        else if(*i=='(')
        {
            push_(*i);
        }
        else if(*i==')')
        {
            while((temp=pop_())!='(')
            {
                printf("%c",temp);
                postfix[++j]=temp;
            }
        }
        else 
        {
            while(pre(*i)<pre(stack[top]))
            {
                temp=pop_();
                printf("%c",temp);
                postfix[++j]=temp;
            }
             push_(*i);
        }
        i++;
    }

    while(top>=0)
    {
        temp=pop_();
        printf("%c",temp);
        postfix[++j]=temp;
    }

    printf("The postfix form is ");
    for(int i=0;i<=j;i++)
    {
        printf("%c",postfix[i]);
    }   
}
