
// Inorder Pre-order Postorder
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
}NODE;
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

void inorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(NODE *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(NODE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{
    int i,n,data;
    NODE *temp,*root=NULL;
    printf("\n How many Elements"); 
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("\n Enter %d element:",i);
                scanf("%d",&data);
                root=createbst(root,data);
            }
    printf("\n IN-ORDER :\n");
    inorder(root);
    printf("\n PRE-ORDER :\n");
    preorder(root);
    printf("\n POST-ORDER :\n");
    postorder(root);
