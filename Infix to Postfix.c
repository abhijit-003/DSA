/* Infix To Postfix */
#include<stdio.h>
#define MAXSIZE 20

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

int priority(char ch)
{
    switch(ch)
    {
        case '(': return 0;break;
        case '+':
        case '-': return 1;break;
        case '*':
        case '/':
        case '%': return 2;break;
        case '$':
        case '^': return 3;break;
    }
    return 0;
}

void convert(char infix[20],char post[20])
{
    int i,j=0;
    char ch,ch1;
    STACK s;
    initstack(&s);
    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];
        switch(ch)
        {
        case '(': push(&s,ch);
           break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '$':
        case '^':
        {
        while(!isempty(&s) && (priority(peek(&s))>=priority(ch)))
        post[j++]=pop(&s);
        push(&s,ch);
        }
        break;
        case ')':
        while((ch1 = pop(&s))!='(')
        {
            post[j++]=ch1; 
        }break;
        default:
        post[j++]=ch;
        }
    }
    while(!isempty(&s))
    post[j++]=pop(&s);
    post[j]='\0';
}

int main()
{
    char infix[20], post[20];
    printf("\n Enter the infix string:");
    scanf("%s",infix);
    convert(infix,post);
    printf("\n The Postfix String Is %s",post);
}
