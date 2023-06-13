/*Insertion Sort 22653*/

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

void insrtionsort(int A[],int n)

{

    int i,j,key;

    for(i=1;i<n;i++)

    {

        key=A[i];

        for(j=i-1;j>=0;j--,compcount++)

        {

            if(key<A[j])

            {

                A[j+1]=A[j];

            }

            else{

                break;

            }

        }

        A[j+1]=key;

    }

}

void main()

{

    int i,n,A[20],num,pos;

    printf("\nThis is bubble sort..");

    printf("\n Enter How Many Elements:");

    scanf("%d",&n);

    accept(A,n);

    printf("\n Accepted Elements:");

    display(A,n);

    insrtionsort(A,n);

    printf("\n Sorted elements");

    display(A,n);

    printf("\nTotal no. of Comparisons =%d",compcount);

    return 0; 

}

/* output:

  This is bubble sort..

 Enter How Many Elements:4

 Enter 0 Element:3

 Enter 1 Element:2

 Enter 2 Element:1

 Enter 3 Element:0

 Accepted Elements:

 3

 2

 1

 0

 Sorted elements

 0

 1

 2

 3

Total no. of Comparisons =7

[Process completed (code 28) - press Enter]*/
