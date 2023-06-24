/*Selection Sort */
#include<stdio.h>
#include<stdlib.h>

int compcount=0;
void accept(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    printf("\n Enter %d Element:",i);
    scanf("%d",&A[i]);
    }
}
void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    printf("\n %d",A[i]);
    }
}
void selectionsort(int A[],int n)
{
    int i,temp,j,smallest,pos;
    for(j=0;j<n-1;j++)
    {
        smallest=A[j];
        pos=j;
        for(i=j+1;i<=n-1;i++, compcount++)
        {
            if(A[i]<smallest)
            {
            smallest=A[i];
            pos=i;
            }
            temp=A[j];
        A[j]=A[pos];
        A[pos]=temp;
        }      
    }
}
void main()
{
    int i,n,A[20],num,pos;
    printf("\n Enter How Many Elements:");
    scanf("%d",&n);
    accept(A,n);
    printf("\n Accepted Elements:");
    display(A,n);
    selectionsort(A,n);
    printf("\n Sorted elements");
    display(A,n);
    printf("\nTotal no. of Comparisons =%d",compcount);
    return 0; 
}

/* output:
 Enter How Many Elements:4

 Enter 0 Element:4

 Enter 1 Element:3

 Enter 2 Element:2

 Enter 3 Element:1

 Accepted Elements:
 4
 3
 2
 1
 Sorted elements
 1
 2
 3
 4
Total no. of Comparisons =6
[Process completed (code 28) - press Enter]*/￼Enter
