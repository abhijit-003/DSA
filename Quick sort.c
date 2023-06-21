/* Quick Sort*/

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

int partition(int A[],int lb,int ub)

{

    int up,dn,temp,pivot;

    up=ub;

    dn=lb+1;

    pivot=A[lb];

    do{

    while((A[dn]<pivot) && (dn<=ub))

    {

        compcount++;

        dn++;

    }

    while((A[up]>pivot) && (up>lb))

    {

        compcount++;

        up--;

    }

    if(dn<up)

    {

        temp=A[dn];

        A[dn]=A[up];

        A[up]=temp;

    }

    }while(dn<up);

    A[lb]=A[up];

    A[up]=pivot;

    return(up);

}

void quicksort(int A[],int lb,int ub)

{

    int i,j;

    if(lb<ub)

    {

        j=partition(A,lb,ub);

        quicksort(A,lb,j-1);

        quicksort(A,j+1,ub);

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

    quicksort(A,0,n-1);

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

[Process completed (code 28) - press Enter] */
