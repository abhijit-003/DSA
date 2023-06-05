/*bubble sort */

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

void bubblesort(int A[],int n)

{

    int i,temp,pass;

    for(pass=1;pass<=n-1;pass++)

    for(i=0;i<=n-pass-1;i++)

    {

        compcount++;

        if(A[i]>A[i+1])

        {

            temp=A[i];

            A[i]=A[i+1];

            A[i+1]=temp;

        }

    }

}

void main()

{

    int i,n,A[20],num,pos;

    printf("\nThis is bubble sort..");

    printf("\n Enter How Many Elements");

    scanf("%d",&n);

    accept(A,n);

    printf("\n Accepted Elements:");

    display(A,n);

    bubblesort(A,n);

    printf("\n Sorted elements");

    display(A,n);

    printf("\nTotal no. of Comparisons =%d",compcount);

    return 0; 

}

/* output:

   This is bubble sort..

 Enter How Many Elements4

 Enter 0 Element:4

 Enter 1 Element:6

 Enter 2 Element:2

 Enter 3 Element:8

 Accepted Elements:

 4

 6

 2

 8

 Sorted elements

 2

 4

 6

 8

Total no. of Comparisons =6

[Process completed (code 28) - press Enter]*/
