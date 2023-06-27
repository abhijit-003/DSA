/*Check Palindrome using stack*/
#include<stdio.h>
#define MAXSIZE 100

typedef struct 
{
    int data[MAXSIZE];
    int top;
} STACK;

void initstack(STACK *ps)
{
    ps->top= -1;
}
void push(STACK *ps,int num)
{
    ps->data[++ps->top]=num;
}
int pop(STACK *ps)
{
    return(ps->data[ps->top--]);
}

int peek(STACK *ps)
{
    return(ps->data[ps->top]);
}
int isempty(STACK *ps)
{
    return(ps->top==-1);
}

int isfull(STACK *ps)
{
    return(ps->top==MAXSIZE - 1);
}

int ispalindrome(char str[20])
{
    int i;
    STACK s;
    initstack(&s);
    for(i=0;str[i]!='\0';i++)
    {
    push(&s,str[i]);
    }
    i=0;
    while(!isempty(&s))
    {
    if(str[i]!=pop(&s))
    {
    return 0;
    }
    i++;
    }
    return 1;
}
int main()
{
    int ans;
    char str[20];
    printf("\n Enter String:");
    scanf("%s",&str);
    ans=ispalindrome(str);
    if(ans==0)
    {
        printf("\n The string %s is not palindrome",str);
    }
    else{
    printf("\n The String %s is Palindrome",str);
    }
    
