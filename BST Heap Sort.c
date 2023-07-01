
// HEAP SORT
#include<stdio.h>
#include<stdlib.h>

void accept(int a[20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n Enter %d Element: ",i);
        scanf("%d",&a[i]);
    }
}

int display(int a[20],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
}

void heapify(int a[], int top, int last)  
{  
    int j,temp,key;
    key=a[top];
    j=2*top+1;
    if((j<last) && (a[j]<a[j+1]))
    {
        j=j+1;
    }
    if ((j<=last) && (key<a[j]))  
    {  
        temp = a[top];  
        a[top]= a[j];   
        a[j] = temp;  
        heapify(a,j,last);  
    }  
}  
  
void heapsort(int a[], int n)  
{  
    int i,temp,top=0,last;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(a,i,n-1);
    }
    for(last=n-1;last>=1;last--)
    {
        temp=a[top];
        a[top]=a[last];
        a[last]=temp;
        printf("\n After %d Iteration :\n",n-last);
        display(a,n);
        heapify(a,top,last-1);
    }
}  
int main()
{
    int i,j,a[20],n;
    printf("\n How many Elements(20): ");
    scanf("%d",&n);
    accept(a, n);
    printf("\n INITIAL HEAP: ");
    printf("\n");
    display(a,n);
    printf("\n");
    heapsort(a,n);
    printf("\n");
    printf("\n SORTED HEAP: ");
    printf("\n");
    display(a,n);
}
