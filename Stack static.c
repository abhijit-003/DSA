
//Static implementation of Stack Operations

#include<stdio.h>
#define  MAX 10  //size of array
int count=0;   //to find total elements in stack
typedef struct stack
{
    int top;
    int data[MAX];
}STACK;

STACK s;   //declaration of stack
void initialize()
{
    s.top=-1;  //top initialize to -1
}
int isempty()
{
    return(s.top==-1);
}
int isfull()
{
   return(s.top==MAX-1);
}
void push(int data)
{
    ++s.top;
    s.data[s.top]=data;
    count++;
}  
int pop()
{
    int num;
    num=s.data[s.top];
    s.top--;
    return(num);
    count--;
}
int peek()
{
     return(s.data[s.top]);
}
int main()
{
    int a,ch,num;
    STACK s;
    initialize();
    do
    {
    printf("\nSELECT THE OPERATION");
    printf("\n 1.PUSH");
    printf("\n 2.POP");
    printf("\n 3.PEEK");
    printf("\n 4.ISEMPTY");
    printf("\n 5.ISFULL");
    printf("\n 6.TOTAL ELEMENTS");
    printf("\n 0.EXIT");
    printf("\nEnter Your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter the Element to Push: ");
            scanf("%d",&num);
            if(isfull()==1)
            {
            printf("\nStack is FULL!!");
            }
            else
            {
            push(num);
            }
            break;
        case 2:
            if(isempty()==1)
            {
            printf("\nStack is empty!!");
            }
            else
            {
                num=pop();
                printf("\nPoped Element is %d.",num);
    
            }
            break;
        case 3:
            if(isempty()==1)
            {
            printf("\nStack is empty!!");
            }
            else
            {
            num=peek();
            printf("\n Top element is: %d",num);
            }
            break;

        case 4:
            if(isempty()==1)
            {
            printf("\nStack is empty!!");
            }
            else
            {
            printf("\nStack is NOT empty!!");
            }
            break;
        case 5:
            if(isfull()==1)
            {
            printf("\nStack is FULL!!");
            }
            else
            {
            printf("\nStack is NOT FULL!!");
            }
            break;
            break;
        case 6:
            printf("\nTotal Elements is Stack are %d",count);
            break;
        case 0:
            exit(0);
            break;
        default:
        printf("\nEnter correct choice!!");
    }    
    }while(ch!=0);
