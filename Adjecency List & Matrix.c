
//Adjecency List and Matrix of Graph

#include<stdio.h>

typedef struct node
{
    struct node *next;
    int vertex;
} NODE;

NODE *list[10];
void createmat(int m[10][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            m[i][j]=0;
            if(i!=j)
            {
                printf("\n Is ther is Edge Between%d & %d (1/0):",i+1,j+1);
                scanf("%d",&m[i][j]);
            }
        }
    }
}

int displaymat(int m[10][10],int n)
{
    int i,j;
    printf("\n The adjecency Matrix : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("\t%d",m[i][j]);
        }
        printf("\n");
    }
}

void createlist(int m[10][10],int n)
{
    int i,j;
    struct node *temp,*newnode;
    for(i=0;i<n;i++)
    {
        list[i]=NULL;
        for(j=0;j<n;j++)
        {
            if(m[i][j]==1)
            {
            newnode=(NODE *) malloc(sizeof(NODE));
            newnode->vertex=j+1;
            newnode->next=NULL;
            if(list[i]==NULL)
            {
            list[i]=temp=newnode;
            }
            else{
            temp->next=newnode;
            temp=newnode;
            }
            }
        }
    }
}

void displaylist(int n)
{
    struct node *temp;
    int i;
    printf("\n The Adjecency Liat :\n");
    for(i=0;i<n;i++)
    {
        printf("\nv%d->",i+1);
        temp=list[i];
        while(temp)
        {
        printf("v%d->",temp->vertex);
        temp=temp->next;
        }
        printf("NULL");
    }
}

int main()
{
    int m[10][10],i,j,n;
    printf("\n How many Vertices: ");
    scanf("%d",&n);
    createmat(m,n);
    displaymat(m,n);
    createlist(m,n);
    displaylist(n);
