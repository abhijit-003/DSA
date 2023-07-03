//26 
// LEVEL ORDER TRAVELSAL
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct node
{
    struct node *left,*right;
    int data;
}NODE;

typedef struct
{
    NODE *data[MAXSIZE];
    int front,rear;
}QUEUE;

void initque(QUEUE *p)
{
    p->front=p->rear=-1;
}
void addque(QUEUE *p, NODE *node)
{
    p->data[++p->rear] = node;
}
NODE* removeque(QUEUE *p)
{
    return(p->data[++p->front]);
}
int isempty(QUEUE *p)
{
    return(p->front==p->rear);
}
//create BST
NODE *createbst(NODE *root,int data)
{
    if(root==NULL)
    {
        root=(NODE *) malloc(sizeof(NODE));
        root->right=root->left=NULL;
        root->data=data;
        return(root);
    }
    else{
        if(data<root->data)
        {
            root->left=createbst(root->left,data);
        }
        else
        if(data>root->data)
        {
            root->right=createbst(root->right,data);
        }
        else
        {
            printf("\n Duplicate Data is Not Allowed!!");
        }
        return(root);
    }
}

void levelorder(NODE *root)
{
    int i,level=0;
    NODE *temp,*marker=NULL;
    QUEUE q;
    initque(&q);
    addque(&q,root);
    addque(&q,marker);
    printf("\n LEVEL %d--->",level);
    while(!isempty(&q))
    {
        temp=removeque(&q);
        if(temp==marker)
        {    
            level++;
            if(!isempty(&q))
            {
                addque(&q,marker);
                printf("\n Level %d--->",level);
            }
        }
        else{
            printf(" %d\t",temp->data);
            if(temp->left)
            {
                addque(&q,temp->left);
            }
            if(temp->right)
            {
                addque(&q,temp->right);
            }
        }
    }
}
int main()
{
    int i,j,n,d;
    NODE *root=NULL;
    printf("\n How many Elements"); 
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("\n Enter %d element:",i);
                scanf("%d",&d);
                root=createbst(root,d);
            }
    printf("\n Level Order Traversal Is:\n");
    levelorder(root);
}
